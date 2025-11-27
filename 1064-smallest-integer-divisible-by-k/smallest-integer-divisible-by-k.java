class Solution {
    public int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        
        int val = 1;
        int count = 1;
        while(val % k != 0) {
            val *= 10;
            val += 1;
            val %= k;
            count ++;
        }
        return count;
    }
}