class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int maxSum = nums[0];
        int minSum = nums[0];

        int currMaxSum = nums[0];
        int currMinSum = nums[0];

        int totalSum = nums[0];

        for(int i=1; i<nums.length; i++) {
            currMaxSum = Math.max(nums[i], nums[i] + currMaxSum);
            currMinSum = Math.min(nums[i], nums[i] + currMinSum);

            maxSum = Math.max(maxSum, currMaxSum);
            minSum = Math.min(minSum, currMinSum);

            totalSum += nums[i];
        }

        if(maxSum < 0) return maxSum;
        return Math.max(maxSum, totalSum - minSum);

    }
}