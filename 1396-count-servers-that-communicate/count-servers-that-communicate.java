class Solution {
    public  boolean isLeft(int row,int col, int[][] grid)
    {
        for(int i=col-1; i>=0; i--)
        {
            if(grid[row][i] == 1) return true;
        }
        return false;
    }
    public  boolean isRight(int row,int col,int bound, int[][] grid)
    {
        for(int i=col+1; i<bound; i++)
        {
            if(grid[row][i] == 1) return true;
        }
        return false;
    }
    public  boolean isTop(int row,int col,int[][] grid)
    {
        for(int i=row-1; i>=0; i--)
        {
            if(grid[i][col] == 1) return true;
        }
        return false;
    }
    public  boolean isBottom(int row,int col,int bound, int[][] grid)
    {
        for(int i=row+1; i<bound; i++)
        {
            if(grid[i][col] == 1) return true;
        }
        return false;
    }
    public int countServers(int[][] grid) {
        int count = 0;
        int rowSize = grid.length;
        int colSize = grid[0].length;
        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(grid[i][j] == 1 && 
                (
                    isLeft(i, j, grid) ||
                    isRight(i, j, colSize, grid) ||
                    isTop(i, j, grid) ||
                    isBottom(i, j, rowSize, grid)
                )
                )count ++;
            }
        }
        return count;
    }
}