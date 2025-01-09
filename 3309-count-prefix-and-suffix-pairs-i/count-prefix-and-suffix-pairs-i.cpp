class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                string str1 = words[i];
                string str2 = words[j];
                int strSize = str1.size();
                if(str2.substr(0,strSize) == str1 && str2.substr(str2.size() - strSize) == str1) ans ++;
            }
        }
        return ans;
    }
};