class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        map<char,int> mp;
        int a = 0, b = 0;
        while(b < s.size())
        {
            mp[s[b]] ++;
            while(mp.size() == 3)
            {
                result += s.size() - b;
                mp[s[a]] --;
                if(mp[s[a]] == 0) mp.erase(s[a]);
                a++;
            }
            b++;
        }
        return result;
    }
};