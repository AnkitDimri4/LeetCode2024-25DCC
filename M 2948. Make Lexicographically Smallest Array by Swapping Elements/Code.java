import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] arr, int limit) {
        int[] sorted = arr.clone();
        Arrays.sort(sorted);
        
        List<List<Integer>> groups = new ArrayList<>();
        List<Integer> groupHeads = new ArrayList<>();
        List<Integer> currentGroup = new ArrayList<>();
        
        // Group elements based on the limit condition
        for (int i = 0; i < sorted.length; i++) {
            if (i > 0 && sorted[i] - sorted[i - 1] > limit) {
                groups.add(currentGroup);
                groupHeads.add(currentGroup.get(0));
                currentGroup = new ArrayList<>();
            }
            currentGroup.add(sorted[i]);
        }
        groups.add(currentGroup);
        groupHeads.add(currentGroup.get(0));
        
        // Create iterators for each group
        List<Iterator<Integer>> groupIters = new ArrayList<>();
        for (List<Integer> group : groups) {
            groupIters.add(group.iterator());
        }
        
        // Replace elements in the original array with the smallest available value from their group
        for (int i = 0; i < arr.length; i++) {
            int x = arr[i];
            int idx = Collections.binarySearch(groupHeads, x);
            if (idx < 0) {
                idx = -idx - 2;
            }
            Iterator<Integer> groupIter = groupIters.get(idx);
            arr[i] = groupIter.next();
        }
        
        return arr;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] nums1 = {1, 5, 3, 9, 8};
        int limit1 = 2;
        System.out.println("Output 1: " + Arrays.toString(solution.lexicographicallySmallestArray(nums1, limit1)));

        // Example 2
        int[] nums2 = {1, 7, 6, 18, 2, 1};
        int limit2 = 3;
        System.out.println("Output 2: " + Arrays.toString(solution.lexicographicallySmallestArray(nums2, limit2)));

        // Example 3
        int[] nums3 = {1, 7, 28, 19, 10};
        int limit3 = 3;
        System.out.println("Output 3: " + Arrays.toString(solution.lexicographicallySmallestArray(nums3, limit3)));
    }
}
