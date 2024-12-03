class Solution {
    public String addSpaces(String s, int[] spaces) {
        int prev = 0;
        StringBuilder str = new StringBuilder();
        for(int i : spaces)
        {
            str.append(s.substring(prev,i));
            str.append(" ");
            prev = i;
        }
        str.append(s.substring(prev));
        return str.toString();
    }
}