from typing import List

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        res = [[0] * n for _ in range(m)]
        i = 0
        while i < len(original):
            res[i // n][i % n] = original[i]
            i += 1
        return res

sol = Solution()
original = [1, 2, 3, 4]
m, n = 2, 2
result = sol.construct2DArray(original, m, n)
for row in result:
    print(" ".join(map(str, row)))
