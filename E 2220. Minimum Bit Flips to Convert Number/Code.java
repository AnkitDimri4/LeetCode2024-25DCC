public class Solution {
    public int minBitFlips(int start, int goal) {
        int count = 0;
        int x = start ^ goal;
        while (x > 0) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int start = 10, goal = 7; 
        System.out.println("Minimum bit flips: " + sol.minBitFlips(start, goal));
    }
}
