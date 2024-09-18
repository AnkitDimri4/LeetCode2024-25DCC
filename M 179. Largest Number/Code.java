import java.util.Arrays;

class Solution {
    public String largestNumber(int[] nums) {
        String[] s = new String[nums.length];
        for (int i = 0; i < nums.length; i++) s[i] = String.valueOf(nums[i]);
        Arrays.sort(s, (a, b) -> (b + a).compareTo(a + b));
        String res = String.join("", s);
        return res.charAt(0) == '0' ? "0" : res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {10, 2};
        int[] nums2 = {3, 30, 34, 5, 9};

        System.out.println("Output 1: " + sol.largestNumber(nums1)); // Output: "210"
        System.out.println("Output 2: " + sol.largestNumber(nums2)); // Output: "9534330"
    }
}
