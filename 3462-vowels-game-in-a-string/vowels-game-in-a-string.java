class Solution {

    boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public boolean doesAliceWin(String s) {
        for(int i=0; i<s.length(); i++) {
            if(isVowel(s.charAt(i))) return true;
        }
        return false;
    }
}