import java.util.Arrays;

class Solution {
    public boolean checkInclusion(String p, String s) {
        if (p.length() > s.length()) return false;
        int[] f1 = new int[26], f2 = new int[26];
        for (int i = 0; i < p.length(); i++) {
            f1[p.charAt(i) - 'a']++;
            f2[s.charAt(i) - 'a']++;
        }
        for (int i = p.length(); i < s.length(); i++) {
            if (Arrays.equals(f1, f2)) return true;
            f2[s.charAt(i) - 'a']++;
            f2[s.charAt(i - p.length()) - 'a']--;
        }
        return Arrays.equals(f1, f2);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String p = "ab"; 
        String s = "eidbaooo"; 
        boolean result = sol.checkInclusion(p, s);
        System.out.println(result); // Output: true
    }
}
