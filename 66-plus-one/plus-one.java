class Solution {
    public int[] plusOne(int[] digits) {
        int it = digits.length-1;
        while(it >= 0) {
            if(digits[it] == 9) {
                digits[it--] = 0;
                continue;
            } 
            digits[it] += 1;
            it--;
            return digits;
        }
        int [] newArray = new int[digits.length+1];
        newArray[0] = 1;
        return newArray;
    }
}