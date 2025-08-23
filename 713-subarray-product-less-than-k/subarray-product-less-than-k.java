class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if(k <= 1) return 0;
        int product = 1;
        int ans = 0;
        int b = 0;
        for(int a=0; a<nums.length; a++) {
            
            product *= nums[a];

            while(product >= k) {
                product /= nums[b];
                b++;
            }

            ans += (a-b+1);
        }
        return ans;
    }
}