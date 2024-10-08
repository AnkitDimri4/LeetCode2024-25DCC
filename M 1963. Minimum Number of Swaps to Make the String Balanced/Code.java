class Solution {
    public int minSwaps(String s) {
        int o = 0, un = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') o++;
            else if (o > 0) o--;
            else un++;
        }
        return (un + 1) / 2;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String input = "]]][[[";
        int result = sol.minSwaps(input);
        System.out.println("Input: " + input);
        System.out.println("Minimum Swaps Required: " + result);  // Output: 2
    }
}
