class Solution {

    public boolean isBalanced(HashMap<Character, Integer> freq) {
        int prev = -1;
        for(Map.Entry<Character, Integer> entry : freq.entrySet()) {
            int curr = entry.getValue();
            if(prev == -1) {
                prev = curr;
            } else if(curr != prev){
                return false;
            }
        }
        return true;
    }

    public int longestBalanced(String s) {
        int maxValue = 1;
        for(int i=0; i<s.length(); i++) {
            HashMap<Character, Integer> freq = new HashMap<>();
            for(int j=i; j<s.length(); j++) {
                freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0) + 1);
                boolean isBalanced = isBalanced(freq);
                if(isBalanced) {
                    int length = j - i + 1;
                    maxValue = Math.max(maxValue, length);
                }
            }
        }
        return maxValue;
    }
}