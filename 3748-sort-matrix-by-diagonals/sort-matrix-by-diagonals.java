class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int size = grid.length;
        for(int i=0; i<size; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            int b=0;
            for(int a=i; a<size; a++) {
                list.add(grid[a][b++]);
            }
            Collections.sort(list, Collections.reverseOrder());
            int index = 0;
            b=0;
            for(int a=i; a<size; a++) {
                grid[a][b++] = list.get(index++);
            }
        }

        for(int i=1; i<size; i++) {
            ArrayList<Integer> list = new ArrayList<>();
            int b=0;
            for(int a=i; a<size; a++) {
                list.add(grid[b++][a]);
            }
            Collections.sort(list);
            int index = 0;
            b=0;
            for(int a=i; a<size; a++) {
                grid[b++][a] = list.get(index++);
            }
        }
        return grid;
    }
}