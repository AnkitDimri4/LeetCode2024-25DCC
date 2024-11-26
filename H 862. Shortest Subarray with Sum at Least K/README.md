
#
---
> ### Intuition 🧩
The goal is to find the shortest subarray with a sum of at least $$k$$. This problem can be efficiently solved using a **deque** combined with **prefix sums**. By leveraging the deque, we can maintain a sliding window to track potential subarray sums, making sure that we efficiently find the shortest subarray that meets the condition.
> ### Approach
We use a **prefix sum array** to track cumulative sums up to each index, allowing quick computation of subarray sums. A **deque** is then utilized for optimization, storing indices of the prefix sum array to efficiently find the shortest subarray with a sum of at least $$k$$. The deque maintains a **monotonic increasing order** of prefix sums, enabling efficient lookups. For each new prefix sum, if the difference between the current prefix sum and the smallest one in the deque is at least $$k$$, we update the result with the shortest subarray length. Additionally, elements at the back of the deque that are greater than or equal to the current prefix sum are removed, as they are unnecessary for future subarrays, thus making sure optimal performance.

### Complexity 📊
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the input array **nums**. Each element is pushed and popped from the deque at most once, leading to a linear time complexity.
- **Space Complexity** $$O(n)$$ for storing the prefix sums and indices.

---

> ### Code 💻
```cpp []
const int MAX_SIZE = 1e5 + 1;
long long psum[MAX_SIZE];
int idx[MAX_SIZE];
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n + 1, s{0}, e{0};
        long long sum{0};
        psum[e] = 0, idx[e++] = -1; // Initialize prefix sum and index
        for (int i{0}; i < n; ++i) {
            sum += nums[i];
            // Check if the current subarray sum is at least k
            while (s < e && sum - psum[s] >= k)
                res = std::min(res, i - idx[s++]);
            // Maintain monotonic increasing order in the deque
            while (s < e && sum <= psum[e - 1])
                e--;
            psum[e] = sum, idx[e++] = i;
        }
        return res > n ? -1 : res;
    }
};
```
---

---
> ### Explanation of the Code
- **Initialization**
  - $$psum[e] = 0$$ and $$idx[e++] = -1$$ are used to handle cases where the subarray starts from the beginning.
- **Main Loop**
  - We iterate over the elements in the array, updating the cumulative sum.
  - The first $$while$$ loop checks if there's a subarray with a sum of at least $$k$$, updating the result if found.
  - The second $$while$$ loop makes sure that the deque maintains a monotonic increasing order of prefix sums by removing unnecessary elements.
- **Return**
  - If no valid subarray is found, return $$-1$$. Otherwise, return the length of the shortest subarray found.

---
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/6f527caa-5ffe-4334-bab9-83574abc1626_1731806692.562703.png)

> [💡 | O(n) | C++ 4ms Beats 99.83% | Deque + Prefix Sum🧠|](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/6053009/o-n-c-4ms-beats-99-83-deque-prefix-sum)


---
