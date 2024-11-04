class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>vec(n,0);
        for(int i=0; i<n; i++)
        {
            string str = words[i];
            if(isVowel(str[0]) && isVowel(str[str.length()-1])) vec[i]++ ;
        }
        vector<int>prefix(n,0);
        prefix[0] = vec[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] + vec[i];
        }
        vector<int>ans;
        for(auto vec : queries)
        {
            int l = 0;
            if(vec[0] > 0)
            {
                vec[0] --;
                l = prefix[vec[0]];
            }
            int r = prefix[vec[1]];
            ans.push_back( r - l);
        }
        return ans;
    }
};