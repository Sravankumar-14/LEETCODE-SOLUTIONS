class Solution {
    public boolean isTrionic(int[] nums) {
        int i = 1;
        int currentStep = 1;
        int counter = 0;
        for(; i<nums.length; i++) {
            if(nums[i] > nums[i-1]) counter ++;
            else break;
        }
        if(counter == 0) return false;
        counter = 0;

        for(; i<nums.length; i++) {
            if(nums[i] < nums[i-1]) counter ++;
            else break;
        }
        if(counter == 0) return false;
        counter = 0;

        for(; i<nums.length; i++) {
            if(nums[i] > nums[i-1]) counter ++;
            else break;
        }
        if(counter == 0) return false;
        if(i != nums.length) return false;
        return true;
    }
}