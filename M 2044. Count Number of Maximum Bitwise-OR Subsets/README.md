#
---

> # Intuition
We need to calculate the maximum bitwise OR possible from any subset of the given numbers. Once we identify that, the task is to count how many subsets achieve this maximum. We can use a backtracking (DFS) approach to explore all subsets, keeping track of the current bitwise OR. If the OR matches the maximum value, we increment the count.

> # Approach
> **Backtracking**: Use DFS to explore all subsets. For each number, we either include it in the subset (updating the OR value) or exclude it, moving recursively to the next number.
> **Max OR Calculation**: First, calculate the maximum possible bitwise OR for all numbers combined. Then, in each recursive call, compare the current OR value with the max OR and count how many subsets reach this maximum.

> # Complexity
- **Time Complexity**: $$O(2^n)$$, where $$n$$ is the size of the input array, as we need to check all subsets (which are $$2^n$$ in total).
- **Space Complexity**: $$O(n)$$, for the recursion stack.

---

> # Code

```cpp []
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a | b; });
        return dfs(nums, 0, 0, maxOr);
    }
private:
    int dfs(vector<int>& nums, int i, int orVal, int maxOr) {
        return i == nums.size() ? (orVal == maxOr) : dfs(nums, i + 1, orVal | nums[i], maxOr) + dfs(nums, i + 1, orVal, maxOr);
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```python []
class Solution:
    def countMaxOrSubsets(self, nums):
        max_or = reduce(lambda a, b: a | b, nums)
        return self.dfs(nums, 0, 0, max_or)
    def dfs(self, nums, i, or_val, max_or):
        return (or_val == max_or) if i == len(nums) else self.dfs(nums, i + 1, or_val | nums[i], max_or) + self.dfs(nums, i + 1, or_val, max_or)
```
```java []
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
}
```

---
![💡 | O(2^n) | C++ 7ms| Java 8ms | Efficient Backtracking 🧠 |]

---
