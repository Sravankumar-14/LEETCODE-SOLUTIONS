class Solution {

    public int maxSequence(char ch, String answerKey, int k) {
        int maxValue = 0;
        int count = 0;
        
        int b = 0;
        for(int i=0; i<answerKey.length(); i++) {
            if(answerKey.charAt(i) != ch) count ++;

            while(count>k && b<i) {
                if(answerKey.charAt(b) != ch) count --;
                b++;
            }

            maxValue = Math.max(maxValue , (i-b+1));
        }
        return maxValue;
    }

    public int maxConsecutiveAnswers(String answerKey, int k) {
        return Math.max(maxSequence('T',answerKey,k) , maxSequence('F',answerKey,k));
    }
}