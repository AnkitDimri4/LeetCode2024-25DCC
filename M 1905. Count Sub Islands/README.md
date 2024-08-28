
##
---
# Intuition
To solve the "Count Sub-Islands" problem, we can use a Depth-First Search (DFS) approach. The key idea is to explore each island in **grid2** and check if it's fully contained within an island in **grid1**. If every cell of an island in **grid2** lies on a corresponding land cell in **grid1**, then it's considered a sub-island.

# Approach
DFS Exploration: For each land cell (**1**) in **grid2**, we perform DFS to explore the entire island starting from that cell, marking visited cells as **0** in **grid2**. During this exploration, we validate whether the current island in **grid2** is a sub-island by checking if each corresponding cell in **grid1** is also land (**1**). If all cells of the island in **grid2** match land cells in **grid1**, the island is considered a sub-island. We then iterate through all cells in **grid2**, and for each unvisited land cell, if DFS confirms it's a sub-island, we increment the sub-island count.

# Complexity
- **Time Complexity** The DFS runs for every land cell in **grid2**, leading to a time complexity of **O(m * n)** where **m** and **n** are the dimensions of the grids.
- **Space Complexity** The space complexity is **O(m * n)** due to the recursive DFS stack.

# Code
```cpp []
class Solution {
public:
    bool explore(vector<vector<int>>& g1, vector<vector<int>>& g2, int x, int y) {
        if (x < 0 || y < 0 || x >= g2.size() || y >= g2[0].size() || g2[x][y] == 0) return true;
        g2[x][y] = 0;
        bool valid = g1[x][y] == 1;
        valid &= explore(g1, g2, x + 1, y);
        valid &= explore(g1, g2, x - 1, y);
        valid &= explore(g1, g2, x, y + 1);
        valid &= explore(g1, g2, x, y - 1);
        return valid;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int count{0};
        for (int i{0}; i < g2.size(); ++i) {
            for (int j{0}; j < g2[0].size(); ++j) {
                if (g2[i][j] == 1 && explore(g1, g2, i, j)) ++count;
            }
        }
        return count;
    }
};
```
```java []
class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int count = 0;
        int m = grid2.length;
        int n = grid2[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && explore(grid1, grid2, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
    private boolean explore(int[][] g1, int[][] g2, int x, int y) {
        if (x < 0 || y < 0 || x >= g2.length || y >= g2[0].length || g2[x][y] == 0) return true;
        g2[x][y] = 0;
        boolean valid = g1[x][y] == 1;
        valid &= explore(g1, g2, x + 1, y);
        valid &= explore(g1, g2, x - 1, y);
        valid &= explore(g1, g2, x, y + 1);
        valid &= explore(g1, g2, x, y - 1);
        return valid;
    }}
```

```python []
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        def explore(g1, g2, x, y):
            if x < 0 or y < 0 or x >= len(g2) or y >= len(g2[0]) or g2[x][y] == 0:
                return True
            g2[x][y] = 0
            valid = g1[x][y] == 1
            valid &= explore(g1, g2, x + 1, y)
            valid &= explore(g1, g2, x - 1, y)
            valid &= explore(g1, g2, x, y + 1)
            valid &= explore(g1, g2, x, y - 1)
            return valid
        count = 0
        for i in range(len(grid2)):
            for j in range(len(grid2[0])):
                if grid2[i][j] == 1 and explore(grid1, grid2, i, j):
                    count += 1
        return count
```

![image.png](https://assets.leetcode.com/users/images/e5b3320c-3765-4bc3-9f03-072f8141549d_1724821819.9891157.png)

- [🌟Efficient DFS Solution for "Count Sub-Islands" | C++ Java Py3 | O(m*n) | 179ms Beats 97.57% |](https://leetcode.com/problems/count-sub-islands/solutions/5700759/efficient-dfs-solution-for-count-sub-islands-c-java-py3-o-m-n-179ms-beats-97-57)
---

