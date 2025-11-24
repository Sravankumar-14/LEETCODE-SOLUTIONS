class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int x = 0;
        List<Boolean> ans = new ArrayList<>();
        
        for(int i=0; i<nums.length; i++) {
            x = (2*x + nums[i]) % 5;
            ans.add(x == 0);
        }
        return ans;
    }
}