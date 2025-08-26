class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        double maxDiagnol = 0.0;
        Map<int[], Double> map = new HashMap<>();
        double diagnol = 0.0;
        for(int[] rectangle : dimensions) {
            diagnol =  Math.sqrt(
                    (rectangle[0] * rectangle[0]) +
                    (rectangle[1] * rectangle[1])
                );
            maxDiagnol = Math.max(maxDiagnol , diagnol);
            map.put(rectangle, diagnol);
        }

        int maxArea = 0;
        for(Map.Entry<int[], Double> entry : map.entrySet()) {
            int[] rect = entry.getKey();
            double val = entry.getValue();
            if(val == maxDiagnol) {
                maxArea = Math.max(rect[0] * rect[1], maxArea);
            }
        }
        return maxArea;
    }
}