

#
---

# Intuition
The goal is to find the longest subarray with the maximum possible bitwise AND value. The maximum bitwise AND can only occur when we have multiple occurrences of the maximum element in the array. Therefore, we first determine the maximum value in the array and then find the longest subarray consisting only of this maximum value.

# Approach
We start by finding the maximum element in the array. Then, we traverse the array to count the length of the longest contiguous subarray where every element equals the maximum value. As soon as an element is not equal to the maximum, we reset the count. Finally, we return the longest length found.

# Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the array. We traverse the array twice — once to find the maximum value and once to calculate the longest subarray.
- **Space Complexity** $$O(1)$$, as we only use a few extra variables.

# Code

```cpp []
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), res{0}, cnt{0};
        for (int n : nums) res = max(res, cnt = (n == mx ? cnt + 1 : 0));
        return res;
    }
};
auto io_opt = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
```

```java []
class Solution {
    public int longestSubarray(int[] nums) {
        int mx = Integer.MIN_VALUE, res = 0, cnt = 0;
        for (int n : nums) mx = Math.max(mx, n);
        for (int n : nums) res = Math.max(res, cnt = (n == mx ? cnt + 1 : 0));
        return res;
    }
}
```

```python []
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx, res, cnt = max(nums), 0, 0
        for n in nums:
            res = max(res, cnt := (cnt + 1 if n == mx else 0))
        return res
```

---
- ![image.png](https://assets.leetcode.com/users/images/92d8adef-bdf5-46e4-b9cf-eb24a28d41a2_1726281824.8252995.png)
- [𝑂(𝑛) | Easy Solution | C++ 35ms Beats 99.56% | Java Py3 |](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14)

---
