import java.util.PriorityQueue;

class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int num : nums) pq.add(num);
        long res = 0;
        while (k-- > 0) {
            int max = pq.poll();
            res += max;
            pq.add((max + 2) / 3);
        }
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 10, 3, 3, 3}; // Example input
        int k = 3; // Example k
        long result = sol.maxKelements(nums, k);
        System.out.println("Output: " + result); // Output the result
    }
}
