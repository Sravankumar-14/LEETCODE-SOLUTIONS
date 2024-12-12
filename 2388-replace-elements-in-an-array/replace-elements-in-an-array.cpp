class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for(auto op : operations)
        {
            int old = op[0];
            int fresh = op[1];
            int idx = mp[old];
            mp.erase(old);
            mp[fresh] = idx;
        }
        for(auto m : mp)
        {
            nums[m.second] = m.first;
        }
        return nums;
    }
};