class Solution {
    public int possibleStringCount(String word) {
        int count = 1;
        char [] array = word.toCharArray();
        char prev = array[0];
        for(int i=1; i<array.length; i++) {
            if(array[i] == prev) count ++;
            prev = array[i];
        }
        return count;
    }
}