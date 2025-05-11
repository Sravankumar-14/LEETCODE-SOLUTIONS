class Solution {

    public boolean isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public int maxVowels(String s, int k) {
        int maxLen = 0;
        int b = 0;
        while(b < k) 
        {
            if(isVowel(s.charAt(b))) maxLen ++;
            b++;
        }
        int a = 0;
        int len = maxLen;
        while(b < s.length())
        {
            if(isVowel(s.charAt(a))) len --;
            a++;
            if(isVowel(s.charAt(b))) len ++;
            b++;
            maxLen = Math.max(len, maxLen);
        }
        return maxLen;

    }
}