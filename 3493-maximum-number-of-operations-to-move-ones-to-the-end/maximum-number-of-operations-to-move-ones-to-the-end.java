class Solution {

    public int maxOperations(String s) {
        int ans = 0;
        int a = 0;
        int size = s.length();
        while(a < size && s.charAt(a) == '0') {
            a++;
        }
        
        int prevOnes = 0;
        while(a < size) {
            int onesCount = 0;
            while(a < size && s.charAt(a) == '1') {
                onesCount ++;
                a++;
            }
            while(a < size && s.charAt(a) == '0') {
                a++;
            }
            if(a == size && s.charAt(a-1) == '1') return ans;
            ans += (prevOnes + onesCount);
            prevOnes += onesCount;
        }
        return ans;
    }
}