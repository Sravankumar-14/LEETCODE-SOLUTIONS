class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int maxSum = 0;
        int sum = 0;
        int b = 0, a = 0, n = nums.length;
        HashSet<Integer>set = new HashSet<>();
        while(b < n)
        {
            while(set.contains(nums[b]) && a < b)
            {
                sum -= nums[a];
                set.remove(nums[a++]);
            }
            set.add(nums[b]);
            sum += nums[b];
            maxSum = Math.max(maxSum,sum);
            b++;
        }
        return maxSum;
    }
}