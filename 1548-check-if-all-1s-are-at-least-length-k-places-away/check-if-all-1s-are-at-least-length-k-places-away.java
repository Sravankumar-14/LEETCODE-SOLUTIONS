class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int i = 0;
        while(i < nums.length && nums[i] != 1) {
            i++;
        }
        i++;
        int count = 0;
        for(; i<nums.length; i++) {
            if(nums[i] == 1) {
                if(count < k) return false;
                count = 0;

            } else{
                count ++;
            }
        }
        return true;
    }

}