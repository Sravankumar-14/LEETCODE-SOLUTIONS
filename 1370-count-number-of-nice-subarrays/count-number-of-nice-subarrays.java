class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        for(int i=0; i<nums.length; i++) {
            if(nums[i] % 2 != 0) list.add(i);
        }
        list.add(nums.length);

        for(int num : list) System.out.println(num);
        int prev = 1;
        int it = k;
        int ans = 0;
        boolean flag = true;
        while(it < list.size()-1) {
            int first = list.get(prev) - list.get(prev-1);
            if(flag) {
                first ++;
                flag = false;
            }
            int second = list.get(it+1) - list.get(it);
            ans += (first * second);
            it++;
            prev++; 
        }
        return ans;
    }
}