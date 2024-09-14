public class Solution {
    public int longestSubarray(int[] nums) {
        int mx = Integer.MIN_VALUE, res = 0, cnt = 0;
        for (int n : nums) mx = Math.max(mx, n);
        for (int n : nums) res = Math.max(res, cnt = (n == mx ? cnt + 1 : 0));
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 3, 3, 2, 2};
        System.out.println(sol.longestSubarray(nums)); // Output: 2
    }
}
