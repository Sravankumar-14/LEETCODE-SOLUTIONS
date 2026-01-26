class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();
        int minValue = Integer.MAX_VALUE;
        for(int i=1; i<arr.length; i++) {
            int curr = arr[i];
            int prev = arr[i-1];
            minValue = Math.min(minValue, (curr - prev));
        }
        for(int i=1; i<arr.length; i++) {
            int curr = arr[i];
            int prev = arr[i-1];
            if(minValue == (curr - prev)) {
                List<Integer> pair = new ArrayList<>();
                pair.add(prev);
                pair.add(curr);
                result.add(pair);
            }
        }
        return result;
    }
}