class Solution {
    public boolean isAllzeroes(int[] nums)
    {
        for(int num : nums)
        {
            if(num != 0) return false;
        }
        return true;
    }
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int [] freq = new int[nums.length + 1];
        for(int i=0; i<queries.length; i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];

            freq[a] += 1;
            freq[b+1] -= 1;
        }
        // System.out.println(Arrays.toString(freq));
        
        for(int i=1; i<freq.length; i++)
        {
            freq[i] += freq[i-1];
        }
        // System.out.println(Arrays.toString(freq));
        for(int i=0; i<nums.length; i++)
        {
            nums[i] -= freq[i];
            if(nums[i] < 0) nums[i] = 0;
        }
        // System.out.println(Arrays.toString(nums));
        return isAllzeroes(nums);
    }
}