class Solution {
    static final int MOD = 1_000_000_007;

    public int[] productQueries(int n, int[][] queries) {
        ArrayList<Integer> powers = new ArrayList<>();
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                powers.add((int) (1L << count));
            }
            count++;
            n >>= 1;
        }

        // prefix product array
        long[] prefix = new long[powers.size()];
        prefix[0] = powers.get(0) % MOD;
        for (int i = 1; i < powers.size(); i++) {
            prefix[i] = (prefix[i - 1] * powers.get(i)) % MOD;
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0) {
                result[i] = (int) prefix[right];
            } else {
                long numerator = prefix[right];
                long denominator = prefix[left - 1];
                result[i] = (int) ((numerator * modPow(denominator, MOD - 2, MOD)) % MOD);
            }
        }
        return result;
    }

    // Fast exponentiation
    private long modPow(long base, long exp, int mod) {
        long res = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
}
