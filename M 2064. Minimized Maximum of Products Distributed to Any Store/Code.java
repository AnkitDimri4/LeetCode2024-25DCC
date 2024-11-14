import java.util.Arrays;

class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int low = 1, high = Arrays.stream(quantities).max().getAsInt();
        while (low < high) {
            int mid = (low + high) / 2, needed = 0;
            for (int q : quantities) needed += (q + mid - 1) / mid;
            if (needed <= n) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test case 1
        int[] quantities1 = {11, 6};
        int stores1 = 6;
        System.out.println("Output 1: " + sol.minimizedMaximum(stores1, quantities1));  // Output: 3

        // Test case 2
        int[] quantities2 = {15, 10, 10};
        int stores2 = 7;
        System.out.println("Output 2: " + sol.minimizedMaximum(stores2, quantities2));  // Output: 5

        // Test case 3
        int[] quantities3 = {100000};
        int stores3 = 1;
        System.out.println("Output 3: " + sol.minimizedMaximum(stores3, quantities3));  // Output: 100000
    }
}
