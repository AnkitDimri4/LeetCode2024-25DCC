public class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String comb = s + "#" + rev;
        int[] kmp = new int[comb.length()];
        for (int i = 1, j = 0; i < comb.length(); ++i) {
            j = kmp[i - 1];
            while (j > 0 && comb.charAt(i) != comb.charAt(j)) j = kmp[j - 1];
            if (comb.charAt(i) == comb.charAt(j)) ++j;
            kmp[i] = j;
        }
        return rev.substring(0, s.length() - kmp[kmp.length - 1]) + s;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String input = "abcd";
        String output = sol.shortestPalindrome(input);
        System.out.println("Input: " + input);
        System.out.println("Output: " + output);
    }
}
