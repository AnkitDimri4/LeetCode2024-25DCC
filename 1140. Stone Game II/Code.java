public class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[][] dp = new int[n + 1][n + 1];
        int[] sum = new int[n + 1];
        int i = n - 1;
        while (i >= 0) {
            sum[i] = piles[i] + (i + 1 < n ? sum[i + 1] : 0);
            i--;
        }
        i = n - 1;
        while (i >= 0) {
            int m = 1;
            while (m <= n) {
                int x = 1;
                while (x <= Math.min(2 * m, n - i)) {
                    dp[i][m] = Math.max(dp[i][m], sum[i] - dp[i + x][Math.max(m, x)]);
                    x++;
                }
                m++;
            }
            i--;
        }
        return dp[0][1];
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] piles = {2, 7, 9, 4, 4};
        int result = sol.stoneGameII(piles);
        System.out.println("Maximum stones Alice can get: " + result);
    }
}
/