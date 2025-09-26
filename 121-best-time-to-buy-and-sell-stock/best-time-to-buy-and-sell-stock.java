class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int rightMaxValue = prices[n-1];
        int maxProfit = 0;

        for(int i=n-2; i>=0; i--) {
            int num = prices[i];
            int profit = rightMaxValue - num;
            profit = (profit > 0) ? profit : 0;
            maxProfit = Math.max(maxProfit, profit);
            rightMaxValue = Math.max(rightMaxValue, num);
        }

        return maxProfit;
    }
}