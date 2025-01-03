class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>zeroes;
        vector<int>ones(n);
        int zeroCount = 0;
        int oneCount = 0;
        for(char ch : s)
        {
            if(ch == '0') zeroCount ++;
            zeroes.push_back(zeroCount);
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '1') oneCount ++;
            ones[i] = oneCount;
            // cout<<oneCount<<" ";
        }
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            ans = max(ans , zeroes[i] + ones[i+1]);
        }
        return ans;
    }
};