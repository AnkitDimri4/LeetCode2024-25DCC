import java.util.Scanner;

class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int max = 0;
        for (int n : nums) max |= n;
        return dfs(nums, 0, 0, max);
    }
    private int dfs(int[] nums, int i, int or, int max) {
        if (i == nums.length) return or == max ? 1 : 0;
        return dfs(nums, i + 1, or | nums[i], max) + dfs(nums, i + 1, or, max);
    }

    // Input/output handling
    public static void main(String[] args) {
        Solution sol = new Solution();
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        
        System.out.print("Enter elements: ");
        for (int i = 0; i < n; ++i) {
            nums[i] = scanner.nextInt();
        }
        
        System.out.println("Number of subsets with maximum OR: " + sol.countMaxOrSubsets(nums));
    }
}
