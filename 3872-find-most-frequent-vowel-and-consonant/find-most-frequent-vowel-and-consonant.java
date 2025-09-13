class Solution {

    public boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int getMaxValue(int[] freq) {
        int maxValue = 0;
        for(int num : freq) {
            maxValue = Math.max(num, maxValue);
        }
        return maxValue;
    }

    public int maxFreqSum(String s) {
        int [] vowelFreq = new int[26];
        int [] consonentFreq = new int[26];

        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            int ascii = ch - 'a';
            if(isVowel(ch)) vowelFreq[ascii] ++;
            else consonentFreq[ascii] ++;
        }

        return (getMaxValue(vowelFreq) + getMaxValue(consonentFreq));
    }
}