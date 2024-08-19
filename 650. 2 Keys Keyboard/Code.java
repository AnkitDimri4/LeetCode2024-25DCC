public class Solution {
    public int minSteps(int n) {
        int s = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                s += i;
                n /= i;
            }
        }
        return s;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 3; 
        System.out.println("Input: n = " + n);
        System.out.println("Output: " + sol.minSteps(n));
    }
}
