class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int [][] matrix = new int[n][n];
        for(int[] query : queries) {
            int a = query[0];
            int b = query[1];
            int x = query[2];
            int y = query[3];
            for(int i=a; i<=x; i++) {
                matrix[i][b] ++;
                if(y < n-1) matrix[i][y+1] --;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        return matrix;
    }
}