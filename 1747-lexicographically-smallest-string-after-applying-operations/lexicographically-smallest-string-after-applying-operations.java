class Solution {

    String addition(String str, int a) {
        char[] ch = str.toCharArray();
        for(int i=1; i<str.length(); i+=2) {
            int num = ch[i] - '0';
            num += a;
            num %= 10;
            char c = (char) (num + '0');
            ch[i] = c;
        }
        return new String(ch);
    }
    
    String reverse(String str, int b) {
        int len = str.length();
        int start = len - b;
        String firstPart = str.substring(start, len);
        String secondPart = str.substring(0, start);
        return (firstPart + secondPart);
    }

    void rec(String str, int a, int b, Set<String> visited) {
        if(visited.contains(str)) return;
        
        String add = addition(str, a);
        String rev = reverse(str, b);
        visited.add(str);

        rec(add, a, b, visited);
        rec(rev, a, b, visited);

    }

    public String findLexSmallestString(String s, int a, int b) {
        Set<String> visited = new HashSet<>();
        rec(s, a, b, visited);
        String small = s;
        for(String str : visited) {
            if(str.compareTo(small) < 0) {
                small = str;
            }
        }

        return small;
    }
}