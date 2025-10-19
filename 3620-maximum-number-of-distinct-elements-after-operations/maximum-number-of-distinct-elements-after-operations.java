class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 0;
        int prev = Integer.MIN_VALUE;
        for(int num : nums) {
            int lower = num - k;
            int upper = num + k;
            if(prev < lower) {
                prev = lower;
                ans++;
            } else if(prev < upper) {
                prev ++;
                ans++;
            }
        }
        return ans;
        
    }
}