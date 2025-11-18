class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int [][] matrix = new int[n][n];
        for(int[] query : queries) {
            int a = query[0];
            int b = query[1];
            int x = query[2];
            int y = query[3];
            for(int i=a; i<=x; i++) {
                for(int j=b; j<=y; j++) {
                    matrix[i][j] ++;
                }
            }
        }
        return matrix;
    }
}