import java.util.Arrays;

class Solution {
    public int[] xorQueries(int[] arr, int[][] q) {
        for (int i = 1; i < arr.length; ++i) arr[i] ^= arr[i - 1];
        int[] res = new int[q.length];
        for (int i = 0; i < q.length; ++i) {
            res[i] = q[i][0] == 0 ? arr[q[i][1]] : arr[q[i][1]] ^ arr[q[i][0] - 1];
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1, 3, 4, 8};
        int[][] queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
        System.out.println(Arrays.toString(sol.xorQueries(arr, queries)));  // Output: [2, 7, 14, 8]
    }
}
