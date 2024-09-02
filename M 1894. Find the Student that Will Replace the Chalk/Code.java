public class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long total = 0;
        for (int c : chalk) total += c;
        k %= total;
        int i = 0;
        while (k >= chalk[i]) k -= chalk[i++];
        return i;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] chalk1 = {5, 1, 5};
        int k1 = 22;
        System.out.println("Output for chalk1: " + sol.chalkReplacer(chalk1, k1)); // Output: 0
        
        int[] chalk2 = {3, 4, 1, 2};
        int k2 = 25;
        System.out.println("Output for chalk2: " + sol.chalkReplacer(chalk2, k2)); // Output: 1
    }
}
