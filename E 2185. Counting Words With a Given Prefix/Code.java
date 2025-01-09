import java.util.*;

class Solution {
    public int prefixCount(String[] words, String pref) {
        int count = 0;
        for (String word : words) {
            if (word.startsWith(pref)) { // Check if word starts with pref
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        String[] words = {"pay", "attention", "practice", "attend"};
        String pref = "at";
        Solution sol = new Solution();
        System.out.println("Count of words with prefix \"" + pref + "\": " + sol.prefixCount(words, pref));
    }
}
