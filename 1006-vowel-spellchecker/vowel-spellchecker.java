class Solution {

    public boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public String modifyVowels(String str) {
        StringBuilder sb = new StringBuilder(str);
        for(int i=0; i<str.length(); i++) {
            if(isVowel(str.charAt(i))){
                sb.setCharAt(i,'*');
            } 
        }
        return sb.toString();
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> actualWordSet = new HashSet<>();
        Map<String, Integer> lowerCaseWordMap = new HashMap<>();
        Map<String, Integer> lowerCaseVowelWordMap = new HashMap<>();

        for(int i=0; i<wordlist.length; i++) {
            String str = wordlist[i];
            actualWordSet.add(str);
            String lowerCaseWord = str.toLowerCase();
            if(!lowerCaseWordMap.containsKey(lowerCaseWord)) {
                lowerCaseWordMap.put(lowerCaseWord,i);
            }
            String masked = modifyVowels(lowerCaseWord);
            if(!lowerCaseVowelWordMap.containsKey(masked)) {
                lowerCaseVowelWordMap.put(masked,i);
            }
        }       

        int size = queries.length;
        String[] ans = new String[size];
        for(int i=0; i<size; i++) {
            String query = queries[i];
            if(actualWordSet.contains(query)) {
                ans[i] = query;
                continue;
            }
            String lowerCaseQuery = query.toLowerCase();
            if(lowerCaseWordMap.containsKey(lowerCaseQuery)) {
                int index = lowerCaseWordMap.get(lowerCaseQuery);
                ans[i] = wordlist[index];
                continue;
            } 
            String lowerCaseVowelQuery = modifyVowels(lowerCaseQuery);
            if(lowerCaseVowelWordMap.containsKey(lowerCaseVowelQuery)) {
                int index = lowerCaseVowelWordMap.get(lowerCaseVowelQuery);
                ans[i] = wordlist[index];
            } else {
                ans[i] = "";
            }
        }
        return ans;

    }
}