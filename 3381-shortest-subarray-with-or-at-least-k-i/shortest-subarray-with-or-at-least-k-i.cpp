class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int orValue = 0, len = 0;
            for(int j=i; j<n; j++)
            {
                orValue |= nums[j];
                len++;
                if(orValue >= k) ans = min(ans,len);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};