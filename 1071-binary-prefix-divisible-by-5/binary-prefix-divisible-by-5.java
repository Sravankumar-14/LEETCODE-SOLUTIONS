class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int x = 0;
        List<Boolean> ans = new ArrayList<>();
        for(int i=0; i<nums.length; i++) {
            ans.add(false);
        }
        for(int i=0; i<nums.length; i++) {
            x = (2*x + nums[i]) % 5;
            if(x == 0) ans.set(i,true);
        }
        return ans;
    }
}