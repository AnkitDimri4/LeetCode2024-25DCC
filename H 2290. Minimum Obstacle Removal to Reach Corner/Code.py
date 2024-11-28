from collections import deque
import sys

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

# Example Usage
sol = Solution()
grid = [[0, 1, 1], [1, 1, 0], [1, 1, 0]]
print(sol.minimumObstacles(grid))  # Output: 2

grid2 = [[0, 1, 0, 0, 0], [0, 1, 0, 1, 0], [0, 0, 0, 1, 0]]
print(sol.minimumObstacles(grid2))  # Output: 0
