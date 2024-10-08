class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>>ans;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        ans.push_back({r,c});
        int d = 0;
        int move = 0;
        while(ans.size() < rows*cols)
        {
            if(d%2 == 0) move++;
            for(int i=0; i<move; i++)
            {
                r += dir[d][0];
                c += dir[d][1];
                if(r>=0 && r<rows && c>=0 && c<cols) ans.push_back({r,c});
            }
            d = (d+1) % 4;
        }
        return ans;
    }
};