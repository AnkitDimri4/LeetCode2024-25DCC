class Solution {
    private int[][] memo;
    private int dp(String s, int i, int j) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int res = dp(s, i + 1, j) + 1;
        for (int k = i + 1; k <= j; k++) {
            if (s.charAt(k) == s.charAt(i)) {
                res = Math.min(res, dp(s, i, k - 1) + dp(s, k + 1, j));
            }
        }
        return memo[i][j] = res;
    }
    public int strangePrinter(String s) {
        int n = s.length();
        memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }
        return dp(s, 0, n - 1);
    }
}
