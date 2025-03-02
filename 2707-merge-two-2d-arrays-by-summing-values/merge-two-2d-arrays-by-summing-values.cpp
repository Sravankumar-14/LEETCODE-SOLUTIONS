class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(vector<int> row : nums1)
        {
            mp[row[0]] += row[1];
        }
        for(vector<int>row : nums2)
        {
            mp[row[0]] += row[1];
        }
        vector<vector<int>>result;
        for(auto mapping : mp)
        {
            result.push_back({mapping.first,mapping.second});
        }
        return result;
    }
};