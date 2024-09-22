import java.util.*;

class Solution {
    public int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long steps = countSteps(cur, n);
            if (steps <= k) {
                cur++;
                k -= steps;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
    
    private long countSteps(long p, long n) {
        long steps = 0;
        for (long f = p, l = p; f <= n; f *= 10, l = l * 10 + 9) {
            steps += Math.min(n + 1, l + 1) - f;
        }
        return steps;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 13, k = 2;
        System.out.println("K-th smallest lexicographical number: " + sol.findKthNumber(n, k)); // Output: 10
    }
}
