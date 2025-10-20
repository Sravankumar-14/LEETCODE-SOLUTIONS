class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums) {
            int rem = ((num % value) + value) % value;
            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }
        int x = 0;
        while(true) {
            int rem = x % value;
            int freq = map.getOrDefault(rem, 0);
            if(freq == 0) return x;
            else {
                freq --;
                map.put(rem, freq);
            }
            x++;
        }
        
    }
}