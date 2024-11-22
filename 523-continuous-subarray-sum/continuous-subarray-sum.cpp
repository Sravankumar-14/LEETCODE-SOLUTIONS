class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefixSum = 0;
        mp[0] = 0;
        for(int i=0; i<nums.size(); i++)
        {
            prefixSum = (prefixSum + nums[i]) % k;
            if(mp.find(prefixSum % k) != mp.end())
            {
                if(i+1 - mp[prefixSum] >= 2) return true;
            }
            else {
                mp[prefixSum] = i+1;
            }
        }
        return false;
    }
};