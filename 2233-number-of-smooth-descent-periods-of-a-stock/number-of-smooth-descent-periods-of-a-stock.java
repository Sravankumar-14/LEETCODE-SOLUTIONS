class Solution {

    public long sum(int n) {
        return (1L * n * (n + 1)) / 2;
    }

    public long getDescentPeriods(int[] prices) {
        long ans = 0;
        int prev = 0;
        for(int i=1; i<prices.length; i++) {
            if(prices[i-1] - prices[i] != 1) {
                ans += sum(i - prev);
                // System.out.println(ans);
                prev = i;
            }
        }
        ans += sum(prices.length - prev);
        return ans;
    }
}