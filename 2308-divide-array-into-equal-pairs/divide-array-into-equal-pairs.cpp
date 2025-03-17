class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 != 0) return false;
        map<int,int> mp;
        for(int num : nums)
        {
            mp[num] ++;
        }
        for(auto m : mp)
        {
            if(m.second % 2 != 0) return false;
        }
        return true;
    }
};