class Solution {
    public long maxPoints(int[][] pts) {
        int r = 1, n = pts[0].length;
        long[] prev = new long[n], curr;
        for (int c = 0; c < n; ++c) prev[c] = pts[0][c];
        while (r < pts.length) {
            curr = prev.clone();
            for (int c = 1; c < n; ++c) curr[c] = Math.max(curr[c], curr[c-1] - 1);
            for (int c = n-2; c >= 0; --c) curr[c] = Math.max(curr[c], curr[c+1] - 1);
            for (int c = 0; c < n; ++c) prev[c] = curr[c] + pts[r][c];
            ++r;
        }
        long maxVal = prev[0];
        for (long val : prev) maxVal = Math.max(maxVal, val);
        return maxVal;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[][] points1 = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
        System.out.println("Maximum points for points1: " + solution.maxPoints(points1));

        int[][] points2 = {{1, 5}, {2, 3}, {4, 2}};
        System.out.println("Maximum points for points2: " + solution.maxPoints(points2));
    }
}
