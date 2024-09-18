class Solution:
    def largestNumber(self, nums):
        s = sorted(map(str, nums), key=lambda x: x*10, reverse=True)
        res = ''.join(s)
        return '0' if res[0] == '0' else res

sol = Solution()
nums1 = [10, 2]
nums2 = [3, 30, 34, 5, 9]

print("Output 1:", sol.largestNumber(nums1))  # Output: "210"
print("Output 2:", sol.largestNumber(nums2))  # Output: "9534330"
