import java.util.*;

class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        int count = 0;
        boolean hasCentralWord = false;

        // Step 1: Build frequency map
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        // Step 2: Iterate through map
        for (String word : map.keySet()) {
            int freq = map.get(word);
            if (freq == 0) continue; // already used

            String reversed = new StringBuilder(word).reverse().toString();

            if (word.equals(reversed)) {
                // Case: Palindromic word like "gg"
                count += (freq / 2) * 4;
                if (freq % 2 == 1) hasCentralWord = true;
            } else if (map.containsKey(reversed)) {
                int revFreq = map.get(reversed);
                int pairs = Math.min(freq, revFreq);
                count += pairs * 4;

                // Mark both words as used
                map.put(word, freq - pairs);
                map.put(reversed, revFreq - pairs);
            }
        }

        if (hasCentralWord) count += 2;

        return count;
    }
}
