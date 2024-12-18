class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        vector<int>alphas(26,0);
        for(int i=0; i<s.size(); i++)
        {
            alphas[s[i] - 'a']++; 
        }
        string str = "";
        for(int i=25; i>=0; i--)
        {
            if(alphas[i] == 0) continue;
            if(alphas[i] <= rl)
            {
                for(int j=0; j<alphas[i]; j++) str += i + 'a';
            }
            else 
            {
                for(int j=0; j<rl; j++) str += i+'a';
                alphas[i] -= rl;
                bool found = false;
                for(int k=i-1; k>=0; k--)
                {
                    if(alphas[k] != 0)
                    {
                        alphas[k]--;
                        str += k + 'a';
                        found = true;
                        i++;
                        break;
                    }
                    
                }
                if(!found) return str;
            }
        }
        return str;
    }
};