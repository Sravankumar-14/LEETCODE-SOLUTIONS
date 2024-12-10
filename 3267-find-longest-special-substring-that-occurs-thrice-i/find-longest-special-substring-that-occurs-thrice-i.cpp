class Solution {
public:
    bool isSpecial(string str)
    {
        for(int i=1; i<str.size(); i++)
        {
            if(str[i] != str[i-1]) return false;
        }
        return true;
    }
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        int maxValue = -1;
        for(int i=0; i<s.size(); i++)
        {
            string str = "";
            for(int j=i; j<s.size(); j++)
            {
                str += s[j];
                if(isSpecial(str)) mp[str]++;
            }
            
        }
        for(auto& m : mp)
        {
            if(m.second >= 3) maxValue = max(maxValue, (int)m.first.size());
        }
        return maxValue;
    }
};