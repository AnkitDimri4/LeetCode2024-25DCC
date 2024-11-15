class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        r = len(arr) - 1
        # Find the longest non-decreasing suffix
        while r > 0 and arr[r] >= arr[r - 1]: r -= 1
        res, l = r, 0
        # Find the longest non-decreasing prefix
        while l < r and (l == 0 or arr[l - 1] <= arr[l]):
            while r < len(arr) and arr[l] > arr[r]: r += 1
            res = min(res, r - l - 1)
            l += 1
        return res

# Example Usage
sol = Solution()
arr1 = [1, 2, 3, 10, 4, 2, 3, 5]
arr2 = [5, 4, 3, 2, 1]
arr3 = [1, 2, 3]

print(f"Test Case 1: {sol.findLengthOfShortestSubarray(arr1)}")  # Expected: 3
print(f"Test Case 2: {sol.findLengthOfShortestSubarray(arr2)}")  # Expected: 4
print(f"Test Case 3: {sol.findLengthOfShortestSubarray(arr3)}")  # Expected: 0
