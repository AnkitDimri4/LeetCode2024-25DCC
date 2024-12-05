#
---
## Intuition 🧩
The problem asks for the minimum number of obstacles to remove to create a path from the top-left corner to the bottom-right corner in a grid. This can be modeled as a **shortest path problem** where moving through obstacles has a weight of 1, and moving through empty cells has a weight of 0. We use a **0-1 Breadth-First Search (BFS)** approach to efficiently solve this problem.

---

## Approach 🎯
**Algorithm Choice** Use **0-1 BFS** with a deque to optimize traversal. In a 0-1 BFS, nodes with weight 0 are added to the front of the deque, and nodes with weight 1 are added to the back. This makes sure that nodes with lower weights are processed first, effectively simulating Dijkstra's algorithm with two-priority levels.
**Initialization** Create a **dist** array to store the minimum obstacles removed to reach each cell. Initialize the starting point with $$dist[0][0] = 0$$ and all other cells to infinity.
**Traversal** Use a deque to perform BFS:
   - For each neighbor $$(nx, ny)$$ of the current cell $$(x, y)$$, calculate the new distance as $$dist[x][y] + grid[nx][ny]$$.
   - If the new distance is smaller than the recorded distance for $$(nx, ny)$$, update the distance and add the cell to the deque. Push to the front if it's an empty cell ($$grid[nx][ny] == 0$$), or to the back if it's an obstacle ($$grid[nx][ny] == 1$$).
   
**Termination** The loop ends when all reachable cells are processed. Return the value at the bottom-right corner $$dist[m - 1][n - 1]$$.

---

### Complexity 📊
- **Time Complexity** $$O(m * n)$$ Each cell is processed at most once, and each edge (neighbor) is relaxed once, resulting in linear time complexity relative to the number of cells.
- **Space Complexity** $$O(m * n)$$  The space is used for the **dist** array and deque, both proportional to the grid size.
---

## Code 💻

```cpp []
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        deque<pair<int, int>> dq{{0, 0}};
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dist[0][0] = 0;
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                    int d = dist[x][y] + grid[nx][ny];
                    if (d < dist[nx][ny]) {
                        dist[nx][ny] = d;
                        grid[nx][ny] == 0 ? dq.push_front({nx, ny}) : dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[r - 1][c - 1];
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
class Solution {
    public int minimumObstacles(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{0, 0});
        int[][] dist = new int[r][c];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        dist[0][0] = 0;
        int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        while (!dq.isEmpty()) {
            int[] cell = dq.pollFirst();
            int x = cell[0], y = cell[1];
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                    int d = dist[x][y] + grid[nx][ny];
                    if (d < dist[nx][ny]) {
                        dist[nx][ny] = d;
                        if (grid[nx][ny] == 0) {
                            dq.offerFirst(new int[]{nx, ny});
                        } else {
                            dq.offerLast(new int[]{nx, ny});
                        }
                    }
                }
            }
        }
        return dist[r - 1][c - 1];
    }
}
```
```python3  []
class Solution:
    def minimumObstacles(self, grid):
        r, c = len(grid), len(grid[0])
        dq = deque([(0, 0)])
        dist = [[sys.maxsize] * c for _ in range(r)]
        dist[0][0] = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while dq:
            x, y = dq.popleft()
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < r and 0 <= ny < c:
                    d = dist[x][y] + grid[nx][ny]
                    if d < dist[nx][ny]:
                        dist[nx][ny] = d
                        if grid[nx][ny] == 0:
                            dq.appendleft((nx, ny))
                        else:
                            dq.append((nx, ny))
        return dist[r - 1][c - 1]
```
---
> ### Explanation of the Code
- **Initialization**
  - A **deque** **dq** is initialized with the starting point $$(0, 0)$$ to perform a 0-1 BFS.
  - A **dist** matrix is initialized with **INT_MAX** to track the minimum obstacles removed to reach each cell, starting with $$dist[0][0] = 0$$.
  - The direction vectors **dx** and **dy** define the possible movements (up, down, left, right).

- **Main Loop**
  - The algorithm processes cells in the deque
    - **Front of the deque** Nodes with fewer obstacles are processed first.
    - For each neighbor $$(nx, ny)$$:
      - **Distance Calculation** Compute $$d = dist[x][y] + grid[nx][ny]$$. If $$grid[nx][ny] == 0$$, no obstacle is removed; otherwise, $$1$$ obstacle is added.
      - **Update Distance** If $$d$$ is smaller than $$dist[nx][ny]$$, update $$dist[nx][ny]$$.
      - **Deque Placement** Push $$(nx, ny)$$ to the front if no obstacle is added ($$grid[nx][ny] == 0$$) or to the back otherwise.
  - This makes sure the shortest path (with the least obstacles removed) is evaluated first.

- **Return**
  - Once the loop completes, the shortest path to the bottom-right corner is stored in $$dist[r-1][c-1]$$. Return this value.


---

---
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/d32bee2e-195b-4ce1-ab29-bbad290fa7d1_1732754762.7838476.png)
> - **Java**
> ![image.png](https://assets.leetcode.com/users/images/82943603-d7d1-4cc3-bfa9-f2bf378f48de_1732756289.3753788.png)
> - **Python3**
> ![image.png](https://assets.leetcode.com/users/images/fe6d0b81-9800-41e5-b72e-5dfba50489d5_1732756904.6106417.png)
[💡|O(m*n)| C++ 95ms Beats 98.80% | Java - 48ms | Py3 - Beats 94.24%| BFS + 0-1 Deque Optimization🧠|](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/solutions/6090237/o-m-n-c-95ms-beats-98-80-java-48ms-py3-beats-94-24-bfs-0-1-deque-optimization)

---
