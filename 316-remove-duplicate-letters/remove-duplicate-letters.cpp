class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        unordered_set<char>sett;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]] = i;
        }
        stack<char>st;
        for(int i=0; i<s.size(); i++)
        {
           if(sett.find(s[i]) != sett.end()) continue;
           while(!st.empty() && st.top()-'a' > s[i]-'a' && i < mp[st.top()])
           {
                sett.erase(st.top());
                st.pop();
           }
           st.push(s[i]);
           sett.insert(s[i]);
            
        }
        string str = "";
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin() , str.end());
        return str;
    }
};