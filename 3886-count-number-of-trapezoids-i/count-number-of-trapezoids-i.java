class Solution {

    // int comibinations(int n, int r) {
    //     int nFact = 1;
    //     while(n != 0) {
    //         nFact *= n;
    //         n--;
    //     }
    //     int rFact = 1;
    //     while(r != 0) {
    //         rFact *= r;
    //         r--;
    //     }
    //     return (nFact) / (nFact * rFact);
    // }

    long combinations(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        if (r == 0 || r == n) {
            return 1;
        }
        if (r > n / 2) {
            r = n - r; // Optimize by choosing the smaller value
        }
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    public int countTrapezoids(int[][] points) {
        int MOD = 1000000007;

        HashMap<Integer,Integer> map = new HashMap<>();
        for(int[] point : points) {
            map.put(point[1], map.getOrDefault(point[1], 0) + 1);
        }

        long res = 0; 
        long prev = 0;

        for(int value : map.values()) {
            long curr = combinations(value, 2);
            res = (res + curr * prev) % MOD;
            prev = (curr + prev) % MOD;
        }

        return (int) res;
    }
}