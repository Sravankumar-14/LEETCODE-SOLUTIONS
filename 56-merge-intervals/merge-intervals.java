class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                // compare first element
                if (a[0] != b[0]) {
                    return Integer.compare(a[0], b[0]);
                }
                // if first element same → compare second element
                return Integer.compare(a[1], b[1]);
            }
        });
        List<int[]> result = new ArrayList<>(); 
        int prevStartTime = intervals[0][0];
        int prevEndTime = intervals[0][1];
        for(int i=1; i<n; i++) {
            int presentStartTime = intervals[i][0];
            int presentEndTime = intervals[i][1];
            if(presentStartTime <= prevEndTime) {
                if(prevEndTime < presentEndTime) prevEndTime = presentEndTime;
                continue;
            }
            int[] arr = new int[2];
            arr[0] = prevStartTime;
            arr[1] = prevEndTime;
            prevStartTime = presentStartTime;
            prevEndTime = Math.max(prevEndTime, presentEndTime);
            result.add(arr);
        }
        int [] arr = new int [2];
        arr[0] = prevStartTime;
        arr[1] = prevEndTime;
        result.add(arr);
        int[][] ans = new int[result.size()][2];
        for(int i=0; i<result.size(); i++) {
            int[] temp = result.get(i);
            ans[i][0] = temp[0];
            ans[i][1] = temp[1];
        }
        return ans;
    }
}