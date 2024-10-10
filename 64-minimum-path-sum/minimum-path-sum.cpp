class Solution {
public:
    int smallPath(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0)
        {
            return grid[m][n];
        }
        if(m < 0 || n < 0) 
        {
            return INT_MAX;
        }
        if(dp[m][n] != INT_MAX) return dp[m][n];
        int up = smallPath(m-1,n,grid,dp);
        int left = smallPath(m,n-1,grid,dp);
        return dp[m][n] = grid[m][n] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,INT_MAX));
        return smallPath(m-1,n-1,grid,dp);
    }
};