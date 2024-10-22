class Solution {
public:
    int rec(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index < 0) return 0;
        if(index == 0) return nums[index];
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + rec(nums,index-2,dp);
        int notPick = rec(nums,index-1,dp);
        if(index >= 0) dp[index] = max(pick, notPick);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return rec(nums,n-1,dp);
    }
};