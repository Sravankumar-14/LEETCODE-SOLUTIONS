class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        if(n < 3) return 0;
        ArrayList<Integer> diff = new ArrayList<>();
        for(int i=1; i<nums.length; i++)
        {
            diff.add(nums[i] - nums[i-1]);
            System.out.println(diff.get(diff.size()-1)); 
        }
        int ans = 0;
        int len = 0;
        for(int i=1; i<diff.size(); i++)
        {
            if(diff.get(i) == diff.get(i-1))
            {
                len ++;
            }
            else 
            {
                if(len > 0) ans += len * (len+1) / 2;
                len = 0;
            }
        }
        if(len > 0)
        {
            ans += len * (len + 1) / 2;
        }
        return ans;
    }
}