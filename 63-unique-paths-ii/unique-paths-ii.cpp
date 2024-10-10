class Solution {
public:
    int findPaths(int m, int n, vector<vector<int>>& ob, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(ob[m][n] == 1) 
        {
            return dp[m][n] = 0;
        }
        int up = findPaths(m-1, n, ob, dp);
        int down = findPaths(m, n-1, ob, dp);
        return dp[m][n] = up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        if(ob[0][0] == 1) return 0;
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return findPaths(m-1,n-1,ob,dp);
    }
};