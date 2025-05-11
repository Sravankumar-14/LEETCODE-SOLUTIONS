class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long  ans = 0;
        int a = 0;
        int b = 0;
        boolean start = false;
        while(b < nums.length)
        {
            if(nums[b] == 0 && !start)
            {
                start = true;
                a = b;
            }
            if(nums[b] != 0 && start)
            {
                start = false;
                long n = b - a;
                ans += n * (n+1) / 2;
            }
            b++;
        }
        if(start)
        {
            long n = nums.length - a;
            ans += n * (n+1) / 2;
        }
        return ans;
    }
}