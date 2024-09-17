import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> m = new HashMap<>();
        for (String word : (s1 + " " + s2).split(" ")) {
            m.put(word, m.getOrDefault(word, 0) + 1);
        }
        List<String> r = new ArrayList<>();
        for (String k : m.keySet()) {
            if (m.get(k) == 1) r.add(k);
        }
        return r.toArray(new String[0]);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = "this apple is sweet", s2 = "this apple is sour";
        String[] result = sol.uncommonFromSentences(s1, s2);

        for (String word : result) System.out.print(word + " ");
    }
}
