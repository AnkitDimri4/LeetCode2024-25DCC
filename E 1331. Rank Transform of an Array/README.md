#
---
> # Intuition
To solve the problem, we need to transform each element of the array into its rank based on its value. The rank must reflect the relative size of the elements, making sure that duplicates receive the same rank. This can be efficiently achieved by sorting the unique values of the array and then mapping each original element to its corresponding rank.

> # Approach
We first create a copy of the array and sort it while removing duplicates using a set. Then, we create a mapping from each unique value to its rank using a dictionary. Finally, we iterate through the original array and replace each element with its corresponding rank from the mapping.

> # Complexity
- **Time Complexity** $$O(n log n)$$, where n is the length of the array. The most time-consuming operation is sorting the array.
- **Space Complexity** $$O(n)$$ for storing the ranks and unique values.

---
# Code
```cpp []
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        if (a.empty()) return {};
        int n = a.size();
        vector<pair<int, int>> b(n);
        for (int i{0}; i < n; ++i) b[i] = {a[i], i};
        sort(b.begin(), b.end());
        for (int r{1}, i{0}; i < n; ++i) {
            a[b[i].second] = r;
            if (i < n - 1 && b[i].first != b[i + 1].first) ++r;
        }
        return a;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```python3 []
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr: return []
        s = sorted(set(arr))
        ranks = {x: i+1 for i, x in enumerate(s)}
        return [ranks[x] for x in arr]
```

```java []
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
}
```
---
> - **CPP**
> -  ![C++](https://assets.leetcode.com/users/images/74acd5e8-6004-4317-9110-6be196920611_1727840258.2237668.png)
> - **Python3**
> -  ![Python](https://assets.leetcode.com/users/images/fa3a4015-6d08-46d1-b73c-be39a4233dc8_1727840326.8068683.png)
> - **Java**
> -  ![Java](https://assets.leetcode.com/users/images/c24e6bf4-3fea-4ea2-9942-a554d96ef3e1_1727840346.0735521.png)
- [O(nlogn)| Easy Solution | C++ 25ms Beats 99.84% | Py3 218ms Beats 99.44% | Java 5ms Beats 100.00% |](https://leetcode.com/problems/rank-transform-of-an-array/description/)

---
> ### Additional Note
> **Note**: While the theoretical complexity provides a framework for understanding performance, real-world implications can vary based on implementation details. The practical performance can often approach O(n) in scenarios with limited unique values, which should be considered when evaluating efficiency.

---
