from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        total = mean * (n + len(rolls))
        miss_sum = total - sum(rolls)
        if miss_sum < n or miss_sum > 6 * n:
            return []
        res = [miss_sum // n] * n
        for i in range(miss_sum % n):
            res[i] += 1
        return res

if __name__ == "__main__":
    sol = Solution()
    rolls = [3, 2, 4, 3]
    mean = 4
    n = 2
    result = sol.missingRolls(rolls, mean, n)

    if not result:
        print("[]")
    else:
        print(result)
