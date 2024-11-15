#

---
> # Intuition 🧩
The problem asks us to find the shortest subarray to remove such that the remaining elements in the array are non-decreasing. This can be achieved by identifying the largest non-decreasing prefix and suffix of the array and then finding the minimum subarray that needs to be removed. We use a $$two-pointer approach$$ to scan for valid subarrays to remove efficiently.

> # Approach
The solution finds the longest non-decreasing prefix and suffix of the array using two pointers ($$l$$ for the prefix and $$r$$ for the suffix). If the array is already sorted, no removal is needed, and the result is 0. The algorithm then uses a sliding window approach to explore all possible subarrays that can be removed, making sure that the remaining elements form a non-decreasing sequence. By adjusting the pointers, it finds the shortest subarray to remove to achieve the desired sorted order.

> # Complexity 📊
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the array. Both prefix and suffix scans take linear time, and we perform one additional scan to find the shortest subarray to remove.
- **Space Complexity** $$O(1)$$ since we only use a constant amount of extra space.

> # Code 💻

```cpp []
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l{0}, r = n - 1;
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0;
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = min(n - l - 1, r);
        for (int i{0}, j = r; i <= l && j < n; ) 
            arr[i] <= arr[j] ? res = min(res, j - i++ - 1) : ++j;
        return res;
    }
};
```
```Java []
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, l = 0, r = n - 1;
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0;
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = Math.min(n - l - 1, r);
        for (int i = 0, j = r; i <= l && j < n; ) 
            if (arr[i] <= arr[j]) res = Math.min(res, j - i++ - 1);
            else ++j;
        return res;
    }
}
```
```Python3 []
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        r = len(arr) - 1
        while r > 0 and arr[r] >= arr[r - 1]: r -= 1
        res, l = r, 0
        while l < r and (l == 0 or arr[l - 1] <= arr[l]):
            while r < len(arr) and arr[l] > arr[r]: r += 1
            res = min(res, r - l - 1)
            l += 1
        return res

```

> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/639d61ac-c4e2-46cd-82db-e00a62e3b68e_1731631079.6325257.png)
> - **Java**
> ![image.png](https://assets.leetcode.com/users/images/f67f7ca3-67b9-4970-b06d-49150a0d8cf7_1731631065.9470758.png)
> - **Python3**
> ![image.png](https://assets.leetcode.com/users/images/134d4d05-1257-45e4-a41d-ab05b21b93c6_1731631057.960208.png)
![💡 | O(n) | C++ 0ms, Java 1ms, Py3 6ms - Beats 100.00% | Two Pointers + Sliding Window 🧠|](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solutions/6046078/o-n-c-0ms-java-1ms-py3-6ms-beats-100-00-two-pointers-sliding-window)

---