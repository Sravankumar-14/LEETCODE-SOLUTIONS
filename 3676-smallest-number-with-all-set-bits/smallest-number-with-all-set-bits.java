class Solution {
    public int smallestNumber(int n) {
        int ans = 0;
        while(n != 0) {
            n >>= 1;
            ans = ans | 1;
            ans <<= 1;
        }
        return ans>>1;
    }
}