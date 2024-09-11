class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0
        x = start ^ goal
        while x:
            count += x & 1
            x >>= 1
        return count

sol = Solution()
start, goal = 10, 7  # Example input
print(f"Minimum bit flips: {sol.minBitFlips(start, goal)}")
