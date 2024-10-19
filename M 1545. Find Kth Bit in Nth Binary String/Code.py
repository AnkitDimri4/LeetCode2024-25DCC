class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        length = (1 << n) - 1
        mid = length // 2 + 1
        return self.findKthBit(n - 1, k) if k < mid else '1' if k == mid else self.invert(self.findKthBit(n - 1, length - k + 1))
    def invert(self, c: str) -> str:
        return '1' if c == '0' else '0' 
sol = Solution()
n, k = 3, 1
print(f"Input: n = {n}, k = {k}\nOutput: {sol.findKthBit(n, k)}")  # Output: 0

n, k = 4, 11
print(f"Input: n = {n}, k = {k}\nOutput: {sol.findKthBit(n, k)}")  # Output: 1
