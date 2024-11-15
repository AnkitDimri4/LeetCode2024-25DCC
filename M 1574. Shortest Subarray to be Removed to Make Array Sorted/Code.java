public class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, l = 0, r = n - 1;
        // Find the longest non-decreasing prefix
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0; // The array is already sorted
        // Find the longest non-decreasing suffix
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = Math.min(n - l - 1, r); // The minimum subarray to remove
        for (int i = 0, j = r; i <= l && j < n; ) 
            if (arr[i] <= arr[j]) res = Math.min(res, j - i++ - 1);
            else ++j;
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
        int[] arr2 = {5, 4, 3, 2, 1};
        int[] arr3 = {1, 2, 3};

        System.out.println("Test Case 1: " + sol.findLengthOfShortestSubarray(arr1)); // Expected: 3
        System.out.println("Test Case 2: " + sol.findLengthOfShortestSubarray(arr2)); // Expected: 4
        System.out.println("Test Case 3: " + sol.findLengthOfShortestSubarray(arr3)); // Expected: 0
    }
}
