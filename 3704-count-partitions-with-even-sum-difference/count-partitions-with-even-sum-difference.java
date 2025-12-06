class Solution {
    public int countPartitions(int[] nums) {
        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }
        int ans = 0;
        int leftSum = 0;
        for(int i=0; i<nums.length-1; i++) {
            int num = nums[i];
            leftSum += num;
            int rightSum = totalSum - leftSum;
            if((leftSum - rightSum) % 2 == 0) {
                System.out.println(leftSum + " - " + rightSum + " = " + (leftSum - rightSum));
                ans ++;
            }
        }
        return ans;
    }
}