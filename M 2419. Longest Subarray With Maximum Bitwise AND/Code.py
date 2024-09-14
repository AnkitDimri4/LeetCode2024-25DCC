from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx, res, cnt = max(nums), 0, 0
        for n in nums:
            res = max(res, cnt := (cnt + 1 if n == mx else 0))
        return res


sol = Solution()
nums = [1, 2, 3, 3, 2, 2]
print(sol.longestSubarray(nums))  # Output: 2
