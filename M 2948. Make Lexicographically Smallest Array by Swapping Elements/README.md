

---

### Intuition 🧩

The goal is to rearrange an array to make it lexicographically smallest, considering a **limit** that groups elements based on their proximity. By leveraging **C++ Ranges**, we can efficiently:
1. **Sort** the array for lexicographical order.
2. **Group** elements based on the **limit** condition.
3. **Iterate** through the original array, replacing elements with the smallest available value from their respective group.

This approach makes sure the output remains lexicographically smallest while respecting the **limit**.

---

### Approach 🎯

1. **Sort** the array - This prepares elements for grouping based on proximity.
2. **Group elements** Use $$ranges::chunk_by$$ to form groups where consecutive elements differ by at most $$limit$$.
3. **Track group heads** Maintain pointers to the smallest unprocessed element in each group.
4. **Replace elements** For each element in the original array, find its group, replace it with the smallest available element, and move the pointer forward.

---

### Complexity 📊
- **Time Complexity** $$O(n log n)$$  
  - Sorting takes $$O(n log n)$$.
  - Grouping and replacing elements are linear operations, $$O(n)$$.

- **Space Complexity** $$O(n)$$ Additional space is used for sorted arrays, group iterators, and group heads.

---

### Code 💻
```cpp []
#include <ranges>
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        auto sorted = arr;
        sort(begin(sorted), end(sorted));
        auto groups = sorted | views::chunk_by([limit](int x, int y) { return y - x <= limit; });
        vector<vector<int>::iterator> group_iters;
        vector<int> group_heads;
        for (auto group : groups) {
            group_iters.push_back(group.begin());
            group_heads.push_back(group.front());
        }
        for (auto& x : arr) {
            auto it = prev(upper_bound(group_heads.begin(), group_heads.end(), x));
            auto& g_it = group_iters[distance(group_heads.begin(), it)];
            x = *g_it++;
        }
        return arr;
    }
};
static auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();
```

---
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/18900d12-990e-4700-b352-04131388ce16_1737765049.4052293.png)
[💡 |O(n log n) C++ 61ms Beats 100.00% | Efficient Lexicographically Smallest Array with Ranges🧠](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/solutions/6325770/on-c-solution-efficient-with-ranges-lexi-9kr0)
---
