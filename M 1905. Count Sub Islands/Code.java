import java.util.*;
class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int count = 0;
        int m = grid2.length;
        int n = grid2[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && explore(grid1, grid2, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
    private boolean explore(int[][] g1, int[][] g2, int x, int y) {
        if (x < 0 || y < 0 || x >= g2.length || y >= g2[0].length || g2[x][y] == 0) return true;
        g2[x][y] = 0;
        boolean valid = g1[x][y] == 1;
        valid &= explore(g1, g2, x + 1, y);
        valid &= explore(g1, g2, x - 1, y);
        valid &= explore(g1, g2, x, y + 1);
        valid &= explore(g1, g2, x, y - 1);
        return valid;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
        int[][] grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
        System.out.println(sol.countSubIslands(grid1, grid2)); // Output: 3
    }
}
