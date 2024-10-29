class Solution {
public:
    int maximum(int top, int middle, int bottom)
    {
        if(top >= middle && top >= bottom) return top;
        if(middle >= top && middle >= bottom) return middle;
        return bottom;
    }
    int rec(vector<vector<int>>& grid, int row, int col, unordered_map<string,int>& dp, int& rowSize, int & colSize,int prev)
    {
        if(row < 0 || row >= rowSize || col >= colSize || col < 0) return 0;
        if(col != 0 && grid[row][col] <= prev) return 0;
        string str = to_string(row) +","+ to_string(col);
        if(dp.find(str) != dp.end()) return dp[str];

        int top = rec(grid, row-1, col+1, dp, rowSize, colSize, grid[row][col]);
        int middle = rec(grid, row, col+1, dp, rowSize, colSize, grid[row][col]);
        int bottom = rec(grid, row+1, col+1, dp, rowSize, colSize, grid[row][col]); 
        int mx = maximum(top,middle,bottom);
        dp[str] = mx;
        return dp[str] + 1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        unordered_map<string, int>dp;
        int maxMoves = 0;
        for(int i=0; i<rowSize; i++)
        {
            int moves = rec(grid,i,0,dp,rowSize,colSize,grid[i][0]);
            maxMoves = max(moves, maxMoves);
        }
        return maxMoves-1;
    }
};