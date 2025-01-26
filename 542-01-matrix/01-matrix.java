class Solution {
    public boolean checkValid(int i, int j, int m, int n)
    {
        return (i >=0 && i<m && j>=0 && j<n);
    }
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] ans = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    queue.offer(new int[] {i,j}); 
                }
                else ans[i][j] = -1;
            }
        } 
        while(! queue.isEmpty())
        {
            int [] current = queue.poll();
            int i = current[0];
            int j = current[1];

            if(checkValid(i+1, j, m, n) && ans[i+1][j] == -1)
            {
                ans[i+1][j] = ans[i][j] + 1;
                queue.offer(new int[] {i+1, j});
            }
            if(checkValid(i-1, j, m, n) && ans[i-1][j] == -1)
            {
                ans[i-1][j] = ans[i][j] + 1;
                queue.offer(new int[] {i-1, j});
            }
            if(checkValid(i, j+1, m, n) && ans[i][j+1] == -1)
            {
                ans[i][j+1] = ans[i][j] + 1;
                queue.offer(new int[] {i, j+1});
            }
            if(checkValid(i, j-1, m, n) && ans[i][j-1] == -1)
            {
                ans[i][j-1] = ans[i][j] + 1;
                queue.offer(new int[] {i, j-1});
            }
        }
        return ans;
    }
}