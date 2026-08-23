class Solution {
    public boolean sumGame(String num) {
        int length = num.length();
        int firstHalfQuestions = 0;
        int secondHalfQuestions = 0;
        int firstHalfSum = 0;
        int secondHalfSum = 0;
        for(int i=0; i<length/2; i++) {
            char ch = num.charAt(i);
            if(ch == '?') firstHalfQuestions ++;
            else firstHalfSum += ch - '0';
        }
        for(int i=length/2; i<length; i++) {
            char ch = num.charAt(i);
            if(ch == '?') secondHalfQuestions ++;
            else secondHalfSum += ch - '0';
        }
        int diffInSums = secondHalfSum - firstHalfSum;
        int diffInQuestions = firstHalfQuestions - secondHalfQuestions; 
        return diffInSums * 2 != diffInQuestions * 9;
    }
}