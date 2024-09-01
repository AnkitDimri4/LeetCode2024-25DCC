import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (original.length != m * n) return new int[0][0];
        int[][] res = new int[m][n];
        int i = 0;
        while (i < original.length) {
            res[i / n][i % n] = original[i];
            i++;
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] original = {1, 2, 3, 4};
        int m = 2, n = 2;
        int[][] result = sol.construct2DArray(original, m, n);
        for (int[] row : result) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
