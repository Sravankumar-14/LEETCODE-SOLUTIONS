class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int>mp;
        for(char ch : s)
        {
            mp[ch] ++;
        }
        int ans = 0;
        for(auto & m : mp)
        {
            int val = m.second;
            if(val % 2 == 0) ans += 2;
            else ans += 1;
        }
        return ans;
    }
};