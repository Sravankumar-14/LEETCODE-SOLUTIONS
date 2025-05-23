class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            curr = max(nums[i] , nums[i] + curr);
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};