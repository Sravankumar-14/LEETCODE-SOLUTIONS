class Solution {
    public void nextPermutation(int[] nums) {
        int firstDigit = -1;
        int n = nums.length;
        int a = -1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                firstDigit = nums[i];
                a = i;
                break;
            }
        }
        System.out.println(firstDigit);
        if(firstDigit == -1) Arrays.sort(nums);
        else
        {
            int b = -1;
            int nextGreater = Integer.MAX_VALUE;
            for(int i=a; i<n; i++)
            {
                if(nums[i] > firstDigit && nums[i] < nextGreater)
                {
                    nextGreater = nums[i];
                    b = i;
                }
            }
            System.out.println(nextGreater);
            nums[a] = nums[a] + nums[b] - (nums[b] = nums[a]);
            Arrays.sort(nums, a+1, n);
        }

    }
}