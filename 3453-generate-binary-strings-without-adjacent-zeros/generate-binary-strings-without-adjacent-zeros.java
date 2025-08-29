class Solution {
    void rec(char ch, int length, char parent, String str, int limit, ArrayList<String> list) {
        String temp = str;
        if((parent == '0' && ch == '0') || length == limit) return;

        temp += ch;
        rec('0', length++, ch, temp, limit, list);
        rec('1', length++, ch, temp, limit, list);
        if(temp.length() == limit) list.add(temp);
        return;
    }

    public List<String> validStrings(int n) {
        ArrayList<String> list = new ArrayList<>();
        rec('0', 0, 'a', "", n, list);
        rec('1', 0, 'a', "", n, list);
        return list;
    }
}