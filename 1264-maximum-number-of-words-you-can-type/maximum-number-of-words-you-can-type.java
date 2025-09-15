class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int [] arr = new int[26];
        for(int i=0; i<brokenLetters.length(); i++) {
            char ch = brokenLetters.charAt(i);
            arr[ch - 'a'] = 1;
        }

        int ans = 0;
        boolean isBroken = false;
        for(int i=0; i<text.length(); i++) {
            char ch = text.charAt(i);
            if(ch == ' ') {
                if(!isBroken) ans ++;
                isBroken = false;
                continue;
            }
            if(arr[ch - 'a'] == 1) isBroken = true;
        }
        if(!isBroken) ans++;
        return ans;
    }
}