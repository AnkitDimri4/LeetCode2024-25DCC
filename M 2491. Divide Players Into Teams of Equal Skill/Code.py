from collections import Counter
from typing import List

class Solution:
    def dividePlayers(self, s: List[int]) -> int:
        t, c, r = 2 * sum(s) // len(s), Counter(s), 0
        for x, y in c.items():
            if y != c[t - x]: return -1
            r += x * (t - x) * y
        return r // 2

if __name__ == "__main__":
    sol = Solution()
    skills = [1, 3, 2, 4]
    result = sol.dividePlayers(skills)
    print("Output:", result)  # Expected Output: 10
