class Solution {
public:
    string findLcs(string str1, string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        
        // Use a DP table to store LCS lengths
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(str1[i-1] == str2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // Reconstruct LCS from DP table
        string lcs = "";
        int i = len1, j = len2;
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                lcs = str1[i-1] + lcs;
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findLcs(str1,str2);
        cout << lcs;
        int a = 0;
        int b = 0;
        for(char c : lcs)
        {
            while(a < str1.size() && str1[a] != c)
            {
                ans += str1[a];
                a++;
            }
            while(b < str2.size() && str2[b] != c)
            {
                ans += str2[b];
                b++;
            }
            ans += c;
            a++;
            b++;
        }
        ans += str1.substr(a) + str2.substr(b);
        return ans;
    }
};