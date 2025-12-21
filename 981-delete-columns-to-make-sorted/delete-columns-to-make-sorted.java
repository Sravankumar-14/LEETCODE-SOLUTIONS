class Solution {
    public int minDeletionSize(String[] strs) {
        int ans  = 0;
        for(int i=0; i<strs[0].length(); i++) {
            for(int j=1; j<strs.length; j++) {
                char prev = strs[j-1].charAt(i);
                char curr = strs[j].charAt(i);
                if(curr < prev){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
}