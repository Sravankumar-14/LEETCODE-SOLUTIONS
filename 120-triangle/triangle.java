class Solution {

    public int rec(int row, int col, List<List<Integer>> triangle, List<List<Integer>> dp) {
        if(row >= triangle.size() || col > row) return 0;

        if(dp.get(row).get(col) != Integer.MAX_VALUE) {
            return dp.get(row).get(col);
        }

        int minValue = Math.min(
            rec(row+1, col, triangle, dp),
            rec(row+1, col+1, triangle, dp)
        );
        dp.get(row).set(col, triangle.get(row).get(col)+ minValue);
        return dp.get(row).get(col);

    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        List<List<Integer>> dp = new ArrayList<>();
        for(int i=0; i<triangle.size(); i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for(int j=0; j<triangle.get(i).size(); j++) {
                row.add(Integer.MAX_VALUE);
            }
            dp.add(row);
        }
        return rec(0, 0, triangle, dp);
    }
}