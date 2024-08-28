from typing import List
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
sol = Solution()
grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
print(sol.countSubIslands(grid1, grid2))  # Output: 3
