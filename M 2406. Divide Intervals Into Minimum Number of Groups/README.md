

#
---
> # Intuition  
To solve this problem, we need to group the intervals such that no two intervals in the same group intersect. By sorting the intervals' start and end times and using a greedy approach, we can track how many intervals are active at any given time and determine the minimum number of groups required.

> # Approach  
We treat each interval as two events: an arrival (interval start) and a departure (interval end + 1). By sorting these events, we can iterate over them to track the number of currently active intervals. The maximum number of overlapping intervals at any point is the answer. The use of a priority queue or sorting makes sure efficiency in this approach.

> # Complexity  
- **Time Complexity** $$O(n log n)$$, where n is the number of intervals due to sorting.  
- **Space Complexity** $$O(n)$$, for storing the events and additional space for tracking groups.

---
> # Code
```cpp []
class Solution {
public:
    int minGroups(vector<vector<int>>& iv) {
        vector<pair<int, int>> ev;
        for (auto& i : iv) ev.emplace_back(i[0], 1), ev.emplace_back(i[1] + 1, -1);
        sort(ev.begin(), ev.end());
        int grp{0}, cur{0};
        for (auto& e : ev) cur += e.second, grp = max(grp, cur);
        return grp;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```

---
> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/39317d51-a48a-4ead-881b-cdeff66d6ed6_1728708051.7008507.png)
![💡Easy Solution | O (n log n) | C++ 175ms Beats 99.77% | Minimum Number of Groups | 🧠](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12)

---
