class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        int i = 0;
        for(; i<s.size(); i++)
        {
            if(k <= 0) break;
            while(!st.empty() && st.top()-'0' > s[i]-'0')
            {
                if(k)
                {
                    st.pop();
                    k--;
                }
                else break;
            }
            st.push(s[i]); 
        }
        string str = "";
        while(!st.empty() && k>0)
        {
            k--;
            st.pop();
        }
        while(!st.empty())
        {
            str += st.top();
            st.pop();
        }
        
        while(str.size()>0 && str.back() == '0') str.pop_back();
        while(str.size() == 0 && s[i] == '0' && i < s.size()) i++;
        i += k;
        reverse(str.begin(),str.end());
        str += s.substr(i);
        if(str == "") return "0";
        return str;
        
    }
};