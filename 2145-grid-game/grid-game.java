class Solution {
    public long gridGame(int[][] grid) {
        long minSum = Long.MAX_VALUE;
        long topSum = 0;
        long bottomSum = 0;
        for(int i=0; i<grid[0].length; i++){
            topSum += grid[0][i];
        }
        for(int i=0; i<grid[0].length; i++){
            topSum -= grid[0][i];
            if(i > 0) bottomSum += grid[1][i-1];
            minSum = Math.min(minSum, Math.max(topSum , bottomSum));
        }
        return minSum;
    }
}