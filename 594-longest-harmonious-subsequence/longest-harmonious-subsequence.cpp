class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp1;
        // unordered_map<int,int>mp2;
        for(int i=0; i<n; i++)
        {
            mp1[nums[i]] ++;
            // mp2[nums[i]] = i;
        }
        int maxi = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp1.find(nums[i] - 1) != mp1.end())
            {
                maxi = max(maxi, mp1[nums[i]] + mp1[nums[i] - 1]);
            }
            if(mp1.find(nums[i] + 1) != mp1.end())
            {
                maxi = max(maxi, mp1[nums[i]] + mp1[nums[i] + 1]);
            }
        }
        return maxi;
    }
};