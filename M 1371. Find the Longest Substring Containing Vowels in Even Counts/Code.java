import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> m = new HashMap<>();
        int b = 0, maxLen = 0;
        m.put(0, -1); 
        for (int i = 0; i < s.length(); ++i) {
            switch (s.charAt(i)) {
                case 'a': b ^= 1 << 0; break;
                case 'e': b ^= 1 << 1; break;
                case 'i': b ^= 1 << 2; break;
                case 'o': b ^= 1 << 3; break;
                case 'u': b ^= 1 << 4; break;
            }
            if (m.containsKey(b)) maxLen = Math.max(maxLen, i - m.get(b));
            else m.put(b, i);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = "eleetminicoworoep";
        String s2 = "leetcodeisgreat";
        String s3 = "bcbcbc";

        System.out.println("Output for \"" + s1 + "\": " + sol.findTheLongestSubstring(s1));
        System.out.println("Output for \"" + s2 + "\": " + sol.findTheLongestSubstring(s2));
        System.out.println("Output for \"" + s3 + "\": " + sol.findTheLongestSubstring(s3));
    }
}
