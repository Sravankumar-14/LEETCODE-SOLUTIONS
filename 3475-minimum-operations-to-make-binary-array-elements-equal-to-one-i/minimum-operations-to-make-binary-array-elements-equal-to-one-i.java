class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;  

        for(int index=0; index<nums.length-2; index++) {
            if(nums[index] == 1) continue;
            ans ++;
            nums[index] = 1;
            nums[index+1] ^= 1;
            nums[index+2] ^= 1;
        }

        int n = nums.length;
        if(nums[n-2] == 0 || nums[n-1] == 0) return -1;  
        return ans;
    }
}