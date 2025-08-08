class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer,Long> map = new HashMap<>();
        int n = nums.length;
        long totalPairs = ((long)(n-1)*(n)) / 2;
        long goodPairs = 0;
        System.out.println(totalPairs);
        for(int i=0; i<n; i++)
        {
            map.put((nums[i] - i) , map.getOrDefault((nums[i] - i), 0L) + 1);
        }
        for(int key : map.keySet())
        {
            long val = map.get(key);
            goodPairs += (val * (val-1)) / 2;
        }
        return totalPairs - goodPairs;
    }
}