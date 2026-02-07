class Solution {
    public int minRemoval(int[] nums, int k) {
        int minValue = Integer.MAX_VALUE;
        int n = nums.length;
        Arrays.sort(nums);

        int j = 0;
        for(int i=0; i<n; i++) {
            if(j < i) j = i;
            while(j < n && nums[j] <= (long)nums[i]*k) {
                j++;
            }

            int kept = (j-i);
            minValue = Math.min(minValue , n-kept);
        }
        return minValue;
    }
}