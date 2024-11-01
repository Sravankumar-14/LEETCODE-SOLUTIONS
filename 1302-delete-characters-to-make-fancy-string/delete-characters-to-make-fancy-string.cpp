class Solution {
public:
    string makeFancyString(string s) {
        string str = "";
        int fancy = 0;
        str += s[0];
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == s[i-1])
            {
                fancy ++;
                if(fancy < 2) 
                {
                    str += s[i];
                }
            }
            else
            {
                fancy = 0;
                str += s[i];
            }
        }
        return str;
    }
};