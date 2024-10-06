import java.util.Arrays;
import java.util.List;

class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        List<String> w1 = Arrays.asList(s1.split(" "));
        List<String> w2 = Arrays.asList(s2.split(" "));
        int i = 0, j = 0, n1 = w1.size(), n2 = w2.size();
        while (i < n1 && i < n2 && w1.get(i).equals(w2.get(i))) ++i;
        while (j < n1 - i && j < n2 - i && w1.get(n1 - 1 - j).equals(w2.get(n2 - 1 - j))) ++j;
        return i + j == n1 || i + j == n2;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String sentence1 = "My name is Haley";
        String sentence2 = "My Haley";

        boolean result = solution.areSentencesSimilar(sentence1, sentence2);
        System.out.println(result); // Output: true
    }
}
