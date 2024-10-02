import java.util.*;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        if (arr == null || arr.length == 0) return new int[0];
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int x : arr) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }
        int range = max - min + 1;
        if (range > 2_000_000) return sortMethod(arr);
        boolean[] count = new boolean[range];
        for (int x : arr) count[x - min] = true;
        int[] ranks = new int[range];
        for (int i = 0, r = 1; i < range; i++) if (count[i]) ranks[i] = r++;
        for (int i = 0; i < arr.length; i++) arr[i] = ranks[arr[i] - min];
        return arr;
    }

    private int[] sortMethod(int[] arr) {
        int[] sorted = arr.clone();
        Arrays.sort(sorted);
        Map<Integer, Integer> rankMap = new HashMap<>();
        for (int i = 0, r = 1; i < sorted.length; i++) {
            if (!rankMap.containsKey(sorted[i])) rankMap.put(sorted[i], r++);
        }
        for (int i = 0; i < arr.length; i++) arr[i] = rankMap.get(arr[i]);
        return arr;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {40, 10, 20, 30};
        int[] result = sol.arrayRankTransform(arr);

        System.out.print("Input: " + Arrays.toString(arr));
        System.out.print("\nOutput: " + Arrays.toString(result));
    }
}
