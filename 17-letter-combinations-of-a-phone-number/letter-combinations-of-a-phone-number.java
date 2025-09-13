class Solution {

    void rec(int digitIndex, String digits, Map<Character, List<Character>> numberList, 
        List<String> ans,  String str) {
            if(digitIndex >= digits.length()) {
                if(str != "") ans.add(str);
                return;
            }
            String temp = str;
            char num = digits.charAt(digitIndex);
            List<Character> list = numberList.get(num);
            for(char ch : list) {
                rec(digitIndex+1, digits, numberList, ans, temp+ch);
            }
            return;
        }

    public List<String> letterCombinations(String digits) {
        Map<Character, List<Character>> numberDigit = new HashMap<>();
        numberDigit.put('2', Arrays.asList('a','b','c'));
        numberDigit.put('3', Arrays.asList('d','e','f'));
        numberDigit.put('4', Arrays.asList('g','h','i'));
        numberDigit.put('5', Arrays.asList('j','k','l'));
        numberDigit.put('6', Arrays.asList('m','n','o'));
        numberDigit.put('7', Arrays.asList('p','q','r','s'));
        numberDigit.put('8', Arrays.asList('t','u','v'));
        numberDigit.put('9', Arrays.asList('w','x','y','z'));

        List<String> ans = new ArrayList<>();
        rec(0, digits, numberDigit, ans, "");
        return ans;
    }
}