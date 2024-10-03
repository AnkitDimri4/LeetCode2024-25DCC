class Solution:
    def minSubarray(self, nums: list[int], p: int) -> int:
        rem = sum(nums) % p
        if rem == 0:
            return 0
        prefix_sum = 0
        res = len(nums)
        index_map = {0: -1}
        for i, num in enumerate(nums):
            prefix_sum = (prefix_sum + num) % p
            if (prefix_sum - rem) % p in index_map:
                res = min(res, i - index_map[(prefix_sum - rem) % p])
            index_map[prefix_sum] = i
        return res if res < len(nums) else -1

if __name__ == "__main__":
    sol = Solution()
    nums = [3, 1, 4, 2]
    p = 6
    result = sol.minSubarray(nums, p)
    print("Minimum subarray length to remove:", result) 
