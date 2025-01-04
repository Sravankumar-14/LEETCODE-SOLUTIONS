class Solution {
    void uniqueStrings(string& s, int start, int end , unordered_set<string>& st)
    {
        for(int i=start+1; i<end; i++)
        {
            string str;
            str.push_back(s[start]);
            str.push_back(s[i]);
            str.push_back(s[end]);
            st.insert(str);
        }
        return;
    }

public:
    int countPalindromicSubsequence(string s) {
        vector<int>startIndex(26,-1);
        vector<int>endIndex(26,-1);
        for(int i=0; i<s.size(); i++)
        {
            if(startIndex[s[i]- 'a'] == -1) startIndex[s[i]-'a'] = i;  
        }
        for(int i=s.size()-1; i>=0; i--)
        {
            if(endIndex[s[i] - 'a'] == -1) endIndex[s[i] - 'a'] = i;
        }
        unordered_set<string>st;
        for(int i=0; i<26; i++)
        {
            if(startIndex[i] == endIndex[i] || startIndex[i] == -1) continue;
            uniqueStrings(s,startIndex[i], endIndex[i] , st);
        }
        return st.size();
    }
};