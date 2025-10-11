class Solution {

    void bfs(int [][] heights, Queue<int[]> queue, boolean[][] visited) {
        int m = heights.length;
        int n = heights[0].length;
        int [][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0];
            int c = cell[1];

            for(int[] d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(!visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr,nc});
                }
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;

        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];

        Queue<int[]> pac = new LinkedList<>();
        Queue<int[]> atl = new LinkedList<>();

        for(int i=0; i<m; i++) {
            pac.offer(new int[]{i,0});
            atl.offer(new int[]{i,n-1});
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }

        for(int j=0; j<n; j++) {
            pac.offer(new int[]{0,j});
            atl.offer(new int[]{m-1,j});
            pacific[0][j] = true;
            atlantic[m-1][j] = true;
        }

        bfs(heights, pac, pacific);
        bfs(heights, atl, atlantic);

        List<List<Integer>> result = new ArrayList<>();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.add(List.of(i,j));
                }
            }
        }

        return result;
    }
}