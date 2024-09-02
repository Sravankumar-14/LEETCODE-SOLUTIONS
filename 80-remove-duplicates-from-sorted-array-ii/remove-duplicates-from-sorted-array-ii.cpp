class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        vector<int>vec;
        for(auto pair : mp)
        {
            if(pair.second == 1) vec.push_back(pair.first);
            else{
                vec.push_back(pair.first);
                vec.push_back(pair.first);
            }
        }
        int size = vec.size();
        vec.resize(n);
        nums = vec;
        return size;
    }
};