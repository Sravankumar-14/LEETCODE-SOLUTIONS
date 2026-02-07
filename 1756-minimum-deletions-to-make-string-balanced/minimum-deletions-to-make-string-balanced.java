class Solution {
    public int minimumDeletions(String s) {
        int ans = Integer.MAX_VALUE;

        int total_a_count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == 'a')
            total_a_count ++;
        }

        int b_left = 0;

        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(ch == 'a') {
                total_a_count --;
            }

            ans = Math.min(ans , b_left + total_a_count);
            if(ch == 'b') {
                b_left ++;
            }
        }
        
        return ans;
    }
}