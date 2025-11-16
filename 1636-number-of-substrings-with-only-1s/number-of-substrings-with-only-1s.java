class Solution {
    static final int MOD = 1000000007;
    public int numSub(String s) {
        long ans = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            long count = 0;
            while(i < n && s.charAt(i) == '1') {
                count ++;
                i++;
            }
            ans = (ans + (count * (count + 1)) / 2) % MOD;
        }
        return (int) ans;
    }
}