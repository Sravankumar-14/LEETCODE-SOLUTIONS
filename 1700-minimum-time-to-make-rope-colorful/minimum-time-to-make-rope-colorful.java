class Solution {
    public int minCost(String colors, int[] neededTime) {
        int sum = 0;
        int maxValue = 0;
        int ans = 0;
        int n = colors.length();
        for(int i=0; i<n-1; i++) {
            sum += neededTime[i];
            maxValue = Math.max(maxValue, neededTime[i]);
            if(colors.charAt(i) != colors.charAt(i+1)) {
                sum -= maxValue;
                ans += sum;
                sum = 0;
                maxValue = 0;
            }
        }
        sum += neededTime[n-1];
        maxValue = Math.max(maxValue, neededTime[n-1]);
        sum -= maxValue;
        ans += sum;
        maxValue = 0;
        return ans;
    }
}