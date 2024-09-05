import java.util.*;

import java.util.Arrays;
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int total = mean * (n + rolls.length);
        int missSum = total - Arrays.stream(rolls).sum(); 
        if (missSum < n || missSum > 6 * n) return new int[0]; 
        int[] res = new int[n];
        Arrays.fill(res, missSum / n);
        int rem = missSum % n; 
        for (int i = 0; i < rem; i++) res[i]++;
        return res;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] rolls = {3, 2, 4, 3};
        int mean = 4, n = 2;
        List<Integer> result = sol.missingRolls(rolls, mean, n);

        if (result.isEmpty()) {
            System.out.println("[]");
        } else {
            for (int num : result) System.out.print(num + " ");
            System.out.println();
        }
    }
}
