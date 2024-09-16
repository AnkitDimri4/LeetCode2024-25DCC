from typing import List

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minutes = []
        for t in timePoints:
            h, m = map(int, t.split(":"))
            minutes.append(h * 60 + m)
        minutes.sort()
        minDiff = 1440 + minutes[0] - minutes[-1] 
        for i in range(1, len(minutes)):
            minDiff = min(minDiff, minutes[i] - minutes[i - 1])
        return minDiff


sol = Solution()
timePoints1 = ["23:59", "00:00"]
timePoints2 = ["00:00", "23:59", "00:00"]

print("Minimum Difference (Example 1):", sol.findMinDifference(timePoints1))  # Output: 1
print("Minimum Difference (Example 2):", sol.findMinDifference(timePoints2))  # Output: 0
