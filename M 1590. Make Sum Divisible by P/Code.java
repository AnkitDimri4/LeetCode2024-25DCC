import java.util.HashMap;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long rem = 0;
        for (int x : nums) rem = (rem + x) % p;
        if (rem == 0) return 0;
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        long pre = 0;
        int res = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            pre = (pre + nums[i]) % p;
            if (mp.containsKey((int)((pre - rem + p) % p))) 
                res = Math.min(res, i - mp.get((int)((pre - rem + p) % p)));
            mp.put((int)pre, i);
        }
        return res == nums.length ? -1 : res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {3, 1, 4, 2};
        int p = 6;
        int result = sol.minSubarray(nums, p);
        System.out.println("Minimum subarray length to remove: " + result);
    }
}
