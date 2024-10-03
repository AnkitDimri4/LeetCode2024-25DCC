#
---
> # Intuition
The problem asks us to remove the smallest subarray such that the sum of the remaining elements is divisible by $$p$$. We can solve this using **prefix sums** and a **hashmap** to track remainders. By tracking the cumulative prefix sums modulo $$p$$ and using the properties of modular arithmetic, we can efficiently find the minimum subarray that satisfies the condition.

> # Approach
To solve the problem, first compute the total sum of the array modulo $$p$$; if the remainder is $$0$$, no subarray needs to be removed. If not, calculate the prefix sum while tracking remainders in a hashmap. Search for a previous prefix sum that, when subtracted from the current prefix sum, results in a sum divisible by $$p$$. By using a hashmap to store prefix sums and their indices, this can be accomplished in a single pass, allowing us to find the minimum length of the subarray that needs to be removed efficiently.

> # Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the array. We traverse the array once while updating the hashmap.
- **Space Complexity** $$O(n)$$ for the hashmap storing prefix sums and indices.


> # Code
```cpp []
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = accumulate(nums.begin(), nums.end(), 0LL) % p, pre = 0, res = nums.size();
        if (!rem) return 0;
        unordered_map<int, int> mp = {{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            pre = (pre + nums[i]) % p;
            if (mp.count((pre - rem + p) % p)) 
                res = min(res, i - mp[(pre - rem + p) % p]);
            mp[pre] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
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
}
```
```python3 []
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        rem = sum(nums) % p
        if rem == 0:
            return 0
        prefix_sum = 0
        res = len(nums)
        index_map = {0: -1}
        for i, num in enumerate(nums):
            prefix_sum = (prefix_sum + num) % p
            if (prefix_sum - rem) % p in index_map:
                res = min(res, i - index_map[(prefix_sum - rem) % p])
            index_map[prefix_sum] = i
        return res if res < len(nums) else -1
```

---
> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/13ed6871-7ba8-4a77-8f62-7c7239576ae5_1727927197.589718.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/87819c3b-44fe-4544-bcb4-72555c6e1749_1727927208.578076.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/0b927ead-88ca-4702-aafa-1287f22094c1_1727927225.772387.png)

---
> ### Additional Note
> **Note**: While the theoretical complexity provides a clear understanding of performance, practical performance can vary based on hardware and input characteristics. Handling remainders efficiently in dynamic situations make sures a consistent time complexity close to **O(n)**.

---
