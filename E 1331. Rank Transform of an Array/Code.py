from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr: return []
        s = sorted(set(arr))
        ranks = {x: i + 1 for i, x in enumerate(s)}
        return [ranks[x] for x in arr]

if __name__ == "__main__":
    sol = Solution()
    arr = [40, 10, 20, 30]
    result = sol.arrayRankTransform(arr)

    print(f"Input: {arr}")
    print(f"Output: {result}")
