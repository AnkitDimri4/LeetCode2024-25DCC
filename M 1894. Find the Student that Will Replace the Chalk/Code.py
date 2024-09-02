from typing import List

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total = sum(chalk)
        k %= total
        i = 0
        while k >= chalk[i]:
            k -= chalk[i]
            i += 1
        return i
sol = Solution()
chalk1 = [5, 1, 5]
k1 = 22
print(f"Output for chalk1: {sol.chalkReplacer(chalk1, k1)}")  # Output: 0

chalk2 = [3, 4, 1, 2]
k2 = 25
print(f"Output for chalk2: {sol.chalkReplacer(chalk2, k2)}")  # Output: 1
