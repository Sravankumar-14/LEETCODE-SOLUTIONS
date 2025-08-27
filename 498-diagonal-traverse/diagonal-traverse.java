class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int rowSize = mat.length;
        int colSize = mat[0].length;

        int [] ans = new int[rowSize * colSize];
        int index = 0;
        for(int i=0; i<colSize; i++) {
            int row = 0;
            int col = i;

            ArrayList<Integer> list = new ArrayList<>();
            while(row < rowSize && col >= 0) {
                list.add(mat[row][col]);
                row ++;
                col --;
            }
            if(i % 2 == 0) {
                for(int a=list.size()-1; a>=0; a--) {
                    ans[index++] = list.get(a);
                }
            }
            else {
                for(int a=0; a<list.size(); a++) {
                    ans[index++] = list.get(a);
                }
            }
        }
        
        for(int i=1; i<rowSize; i++) {
            int row = i;
            int col = colSize-1;

            ArrayList<Integer> list = new ArrayList<>();
            while(row < rowSize && col >= 0) {
                list.add(mat[row][col]);
                row ++;
                col --;
            }
            if((i + colSize - 1) % 2 == 0) {
                for(int a=list.size()-1; a>=0; a--) {
                    ans[index++] = list.get(a);
                }
            }
            else {
                for(int a=0; a<list.size(); a++) {
                    ans[index++] = list.get(a);
                }
            }
        }
        return ans;
    }
}