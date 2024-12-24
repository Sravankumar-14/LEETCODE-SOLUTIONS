class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid (m, vector<int>(n,0));
        for(auto& guard : guards)
        {
            int row = guard[0];
            int col = guard[1];
            grid[row][col] = 1;
        }
        for(auto& wall : walls)
        {
            int row = wall[0];
            int col = wall[1];
            grid[row][col] = 2;
        }
        for(int i=0; i<m; i++)
        {
            bool isGuard = false;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1){
                    isGuard = true;
                    continue;
                }
                if(grid[i][j] == 2)
                {
                    isGuard = false;
                    continue;
                }
                if(isGuard) grid[i][j] = 3;
            }
        }

        for(int i=0; i<n; i++)
        {
            bool isGuard = false;
            for(int j=0; j<m; j++)
            {
                if(grid[j][i] == 1){
                    isGuard = true;
                    continue;
                }
                if(grid[j][i] == 2)
                {
                    isGuard = false;
                    continue;
                }
                if(isGuard) grid[j][i] = 3;
            }
        }

        for(int i=m-1; i>=0; i--)
        {
            bool isGuard = false;
            for(int j=n-1; j>=0; j--)
            {
                if(grid[i][j] == 1){
                    isGuard = true;
                    continue;
                }
                if(grid[i][j] == 2)
                {
                    isGuard = false;
                    continue;
                }
                if(isGuard) grid[i][j] = 3;
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            bool isGuard = false;
            for(int j=m-1; j>=0; j--)
            {
                if(grid[j][i] == 1){
                    isGuard = true;
                    continue;
                }
                if(grid[j][i] == 2)
                {
                    isGuard = false;
                    continue;
                }
                if(isGuard) grid[j][i] = 3;
            }
        }

        int guarded = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) guarded++;
            }
        }
        return guarded;
    }
};