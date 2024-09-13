class Solution:
    def xorQueries(self, arr: list[int], q: list[list[int]]) -> list[int]:
        for i in range(1, len(arr)):
            arr[i] ^= arr[i - 1]
        return [arr[right] ^ arr[left - 1] if left else arr[right] for left, right in q]

# Example usage
sol = Solution()
arr = [1, 3, 4, 8]
queries = [[0, 1], [1, 2], [0, 3], [3, 3]]
print(sol.xorQueries(arr, queries))  # Output: [2, 7, 14, 8]
