#
---

> ### Intuition🧩
This problem asks us to remove a subarray to make the remaining array sorted. We can solve it using a **sliding window** approach by identifying consecutive sequences and checking for the length of valid subsequences where elements differ by 1.

> ### Approach
We use a **counting technique** to track consecutive elements in the array. For every valid subsequence, we update the result array. By iterating through the array and counting the lengths of consecutive subsequences, we can identify the smallest subarray to remove to achieve a sorted array.

> ### Complexity📊
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the array. We traverse the array once.
- **Space Complexity** $$O(n)$$, as we store intermediate results in the **res** array.

---

> ### Code💻
```cpp []
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), count{1};
        vector<int> res(n - k + 1, -1);
        for (int i{1}; i < k; i++) 
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
        if (count == k) res[0] = nums[k - 1];
        for (int i = k; i < n; i++) {
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
            if (count >= k) res[i - k + 1] = nums[i];
        }
        return res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
---
> ### Images
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/cc0e0843-4498-401b-82ac-080faa87ec78_1731722404.234777.png)
[💡 | O(n) | C++ 0ms Beats 100.00% | Sliding Window / Counting Approach 🧠 |](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/solutions/6049390/o-n-c-0ms-beats-100-00-sliding-window-counting-approach)

---