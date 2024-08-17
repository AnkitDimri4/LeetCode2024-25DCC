---

## Intuition
The problem requires selecting one cell from each row of a matrix to maximize the score, factoring in penalties for picking cells that are too far apart in consecutive rows. The key idea is to efficiently propagate the maximum possible points row by row, adjusting for the distance penalty between columns.

## Approach
Use **dynamic programming** to track the maximum points achievable for each column up to the current row. To efficiently account for the distance penalty, make two passes over each row: first from left to right to propagate the maximum points considering penalties, and then from right to left to cover all possible transitions. After processing each row, update the points for each column to reflect the best possible score moving forward.

## Complexity
- **Time Complexity**: $$O(m \times n)$$, where $$m$$ is the number of rows and $$n$$ is the number of columns.
- **Space Complexity**: $$O(n)$$, as we only store the current and previous row's points.

## Code

```cpp []
class Solution {
public:
    long long maxPoints(vector<vector<int>>& pts) {
        int r{1}, n = pts[0].size();
        auto prev = vector<long long>(pts[0].begin(), pts[0].end()), curr = prev;
        while (r < pts.size()) {
            for (auto c{0}; c < n; ++c) curr[c] = prev[c];
            for (auto c{1}; c < n; ++c) curr[c] = max(curr[c], curr[c-1] - 1);
            for (auto c{n-2}; c >= 0; --c) curr[c] = max(curr[c], curr[c+1] - 1);
            for (auto c{0}; c < n; ++c) curr[c] += pts[r][c];
            prev = curr; ++r;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
```

```python []
class Solution:
    def maxPoints(self, pts):
        r, n = 1, len(pts[0])
        prev = pts[0]
        while r < len(pts):
            curr = prev[:]
            for c in range(1, n): curr[c] = max(curr[c], curr[c-1] - 1)
            for c in range(n-2, -1, -1): curr[c] = max(curr[c], curr[c+1] - 1)
            prev = [curr[c] + pts[r][c] for c in range(n)]
            r += 1
        return max(prev)
```

```java []
class Solution {
    public long maxPoints(int[][] pts) {
        int r = 1, n = pts[0].length;
        long[] prev = new long[n], curr;
        for (int c = 0; c < n; ++c) prev[c] = pts[0][c];
        while (r < pts.length) {
            curr = prev.clone();
            for (int c = 1; c < n; ++c) curr[c] = Math.max(curr[c], curr[c-1] - 1);
            for (int c = n-2; c >= 0; --c) curr[c] = Math.max(curr[c], curr[c+1] - 1);
            for (int c = 0; c < n; ++c) prev[c] = curr[c] + pts[r][c];
            ++r;
        }
        long maxVal = prev[0];
        for (long val : prev) maxVal = Math.max(maxVal, val);
        return maxVal;
    }
}
```

- **[Python Beats 100% | Java 12ms | C++ 151ms Beats 97.28% | DP | "Maximum Number of Points with Cost"](https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/5647965/python-beats-100-java-12ms-c-151ms-beats-97-28-dp-maximum-number-of-points-with-cost)**

---