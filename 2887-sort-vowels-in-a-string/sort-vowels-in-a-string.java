class Solution {

    public boolean isVowel(char ch) {
        return(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    public String sortVowels(String s) {
        ArrayList<Character> list = new ArrayList<>();
        ArrayList<Integer> indexes = new ArrayList<>();

        char[] chars = s.toCharArray();

        for(int i=0; i<chars.length; i++) {
            if(isVowel(chars[i])) {
                list.add(chars[i]);
                indexes.add(i);
            }
        }
        
        Collections.sort(list);
        int index = 0;
        for(char ch : list) {
            chars[indexes.get(index++)] = ch;
        }
        
        return new String(chars);
    }
}