class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int [] prefix = new int[n];
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        int ans = 0;
        int temp = nums[n-1];
        if(temp == 0 && temp == prefix[n-1]) ans += 2;
        if(temp == 0 && (Math.abs(temp - prefix[n-1]) == 1)) ans += 1;
        for(int i=n-2; i>=0; i--) {
            temp += nums[i];
            if(temp == prefix[i] && nums[i] == 0) {
                ans += 2;
            } else if(Math.abs(temp - prefix[i]) == 1 && nums[i] == 0) ans +=1;
        }
        return ans;
    }
}