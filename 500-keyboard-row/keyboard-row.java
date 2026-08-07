class Solution {
    public String[] findWords(String[] words) {
        HashSet<Character> firstRow = new HashSet<>();
        HashSet<Character> secondRow = new HashSet<>();
        HashSet<Character> thirdRow = new HashSet<>();
        firstRow.addAll(
            List.of(
                'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'
            )
        );
        secondRow.addAll(
            List.of(
                'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'
            )
        );
        thirdRow.addAll(
            List.of(
                'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'
            )
        );

        List<String> result = new ArrayList<>();
        for(String word : words) {
            List<Character> searchList = new ArrayList<>();
            for(char ch : word.toCharArray()) {
                searchList.add(ch);
            }
            
            boolean isPresent = (
                firstRow.containsAll(searchList) || secondRow.containsAll(searchList) || thirdRow.containsAll(searchList)
            );

            if(isPresent) result.add(word);
        }

        return result.toArray(new String[0]);
        
    }
}