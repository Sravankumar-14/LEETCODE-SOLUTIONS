class Solution {
    public int longestSubarray(int[] nums) {
        int maxValue = 0;
        for(int i=0; i<nums.length; i++)
        {
            maxValue = Math.max(maxValue , nums[i]);
        }
        int count = 0;
        int maxCount = 0;
        for(int val : nums)
        {
            if(val == maxValue)count ++;
            else count = 0;
            maxCount = Math.max(maxCount , count);
        }
        return maxCount;
    }
};