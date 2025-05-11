class Solution {
    public int longestContinuousSubstring(String s) {
        int maxLen = 1;
        int len = 1;
        int prev = (int) s.charAt(0);
        for(int i=1; i<s.length(); i++)
        {
            int curr = (int)s.charAt(i);
            if(curr - prev == 1) len ++;
            else len = 1;
            prev = curr;
            maxLen = Math.max(len , maxLen);
        }
        return maxLen;
    }
}