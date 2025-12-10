class Solution {
    static final int MOD = 1000000007;
    public int factorial(int n) {
        long ans = 1;
        while(n != 0) {
            ans = (ans * n) % MOD;
            n--;
        }
        // System.out.println("ans is " + ans);
        return (int) ans;
    }

    public int countPermutations(int[] complexity) {
        int ans = 0;
        int minValue = complexity[0];
        for(int i=1; i<complexity.length; i++) {
            if(complexity[i] <= minValue) return 0;
        }
        return factorial(complexity.length-1);
    }
}