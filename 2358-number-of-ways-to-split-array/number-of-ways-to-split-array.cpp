class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            long long  firstHalf = prefix[i];
            long long secondHalf = prefix[n-1] - prefix[i];
            if(firstHalf >= secondHalf) ans++;
        }
        return ans;
    }
};