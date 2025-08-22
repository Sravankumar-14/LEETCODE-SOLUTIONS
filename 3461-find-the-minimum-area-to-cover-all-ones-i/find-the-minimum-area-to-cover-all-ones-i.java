class Solution {
    public int minimumArea(int[][] grid) {
        int top = Integer.MAX_VALUE;
        int left = Integer.MAX_VALUE;
        int right = 0;
        int bottom = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 1){
                    top = Math.min(top, i);
                    left = Math.min(left, j);
                    right = Math.max(right, j);
                    bottom = Math.max(bottom, i);
                }
            }
        }
        return((bottom - top + 1) * (right - left + 1));
        // System.out.println(top + " " + left + " " + right + " " + bottom);
    }
}