class pair{
    int value;
    int index;
    public pair(int value, int index)
    {
        this.value = value;
        this.index = index;
    }
}
class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        List<pair>copy = new ArrayList<>();
        for(int i=0; i<nums.length; ++i)
        {
            copy.add(new pair(nums[i] , i));
        }
        Collections.sort(copy, Comparator.comparingInt(pair->pair.value));
        int left = 0;
        int right = 1;
        while(right < nums.length)
        {
            List<Integer> val = new ArrayList<>();
            List<Integer> idx = new ArrayList<>();
            val.add(copy.get(left).value);
            idx.add(copy.get(left).index);
            while(right < nums.length && Math.abs(copy.get(right).value - copy.get(right - 1).value) <= limit)
            {
                val.add(copy.get(right).value);
                idx.add(copy.get(right).index);
                right ++;
            }
            Collections.sort(idx);
            for(int i=0; i<val.size(); i++)
            {
                nums[idx.get(i)] = val.get(i);
            }
            left = right;
            right++;
        }
        return nums;
    }
}