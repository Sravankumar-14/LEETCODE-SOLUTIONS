class Solution {
public:
    int maximum(int top, int middle, int bottom)
    {
        return max(top, max(middle, bottom));
    }

    int rec(vector<vector<int>>& grid, int row, int col, unordered_map<string, int>& dp, int& rowSize, int & colSize, int prev)
    {
        if (row < 0 || row >= rowSize || col < 0 || col >= colSize) return 0; // Boundary check
        if (col != 0 && grid[row][col] <= prev) return 0;  // Strictly increasing check

        string str = to_string(row) + "," + to_string(col); // Unique memoization key
        if (dp.find(str) != dp.end()) return dp[str];  // Use memoized value directly

        // Recursively check the 3 possible directions
        int top = rec(grid, row - 1, col + 1, dp, rowSize, colSize, grid[row][col]);
        int middle = rec(grid, row, col + 1, dp, rowSize, colSize, grid[row][col]);
        int bottom = rec(grid, row + 1, col + 1, dp, rowSize, colSize, grid[row][col]);

        int mx = maximum(top, middle, bottom);  // Get the maximum steps from the three directions
        dp[str] = mx;  // Memoize the result
        return dp[str] + 1;  // Add 1 for the current move
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        unordered_map<string, int> dp;  // Memoization map
        int maxMoves = 0;

        // Try starting from each row in the first column
        for (int i = 0; i < rowSize; i++) {
            int moves = rec(grid, i, 0, dp, rowSize, colSize, grid[i][0]);
            maxMoves = max(moves, maxMoves);  // Keep track of the maximum moves
        }
        return maxMoves - 1;  // Subtract 1 to get the number of "steps" instead of moves
    }
};
