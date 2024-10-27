class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i : nums) mp[i] ++;
        int ans = 0;
        for(int i : nums)
        {
            if(mp.find(k-i) != mp.end())
            {
                if(mp[k-i] > 0)
                {
                    ans ++;
                    mp[k-i] --;
                    mp[i] --;
                    if(mp[i] < 0) ans--;
                }
            }
        }
        return ans;
    }
};