class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=n-1; i>=0; i--) {
            if(i < 2) return 0;
            int first = nums[i];
            int second = nums[i-1];
            int third = nums[i-2];
            if((first+second > third) && (first+third > second) && (second+third > first)) return first+second+third;
        }
        return 0;
    }
}