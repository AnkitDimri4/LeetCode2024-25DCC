import java.util.*;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> minutes = new ArrayList<>();
        for (String t : timePoints) {
            String[] hm = t.split(":");
            int mins = Integer.parseInt(hm[0]) * 60 + Integer.parseInt(hm[1]);
            minutes.add(mins);
        }
        Collections.sort(minutes);
        int minDiff = 1440 + minutes.get(0) - minutes.get(minutes.size() - 1); 
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = Math.min(minDiff, minutes.get(i) - minutes.get(i - 1));
        }
        return minDiff;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> timePoints1 = Arrays.asList("23:59", "00:00");
        List<String> timePoints2 = Arrays.asList("00:00", "23:59", "00:00");

        System.out.println("Minimum Difference (Example 1): " + sol.findMinDifference(timePoints1)); // Output: 1
        System.out.println("Minimum Difference (Example 2): " + sol.findMinDifference(timePoints2)); // Output: 0
    }
}
