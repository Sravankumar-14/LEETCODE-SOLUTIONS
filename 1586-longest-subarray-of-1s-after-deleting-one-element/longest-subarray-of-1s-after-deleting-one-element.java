class Solution {
    public int longestSubarray(int[] nums) {
        int a = 0;
        int maxLen = 0;
        int zeroes = 0;
        boolean anyZeroes = false;
        for(int i=0; i<nums.length; i++)
        {
            if(nums[i] == 0) {
                zeroes ++;
                anyZeroes = true;
            }
            while(a < i && zeroes > 1)
            {
                if(nums[a] == 0) zeroes --;
                a++;
            }
            maxLen = Math.max(maxLen, (i-a));
        }
        // if(!anyZeroes) maxLen --;
        return maxLen;
    }
}