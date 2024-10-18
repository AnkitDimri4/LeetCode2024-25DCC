from functools import reduce

class Solution:
    def countMaxOrSubsets(self, nums):
        max_or = reduce(lambda a, b: a | b, nums)
        return self.dfs(nums, 0, 0, max_or)
    
    def dfs(self, nums, i, or_val, max_or):
        if i == len(nums):
            return or_val == max_or
        return self.dfs(nums, i + 1, or_val | nums[i], max_or) + self.dfs(nums, i + 1, or_val, max_or)

# Input/output handling
if __name__ == "__main__":
    sol = Solution()
    n = int(input("Enter number of elements: "))
    nums = list(map(int, input("Enter elements: ").split()))
    print("Number of subsets with maximum OR:", sol.countMaxOrSubsets(nums))
