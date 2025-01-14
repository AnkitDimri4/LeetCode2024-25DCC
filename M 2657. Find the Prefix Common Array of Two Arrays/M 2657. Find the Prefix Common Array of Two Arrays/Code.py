class Solution:
    def findThePrefixCommonArray(self, A, B):
        n = len(A)
        seen = set()
        C = [0] * n
        commonCount = 0
        for i in range(n):
            if A[i] in seen:
                commonCount += 1
            else:
                seen.add(A[i])
            if B[i] in seen:
                commonCount += 1
            else:
                seen.add(B[i])
            C[i] = commonCount
        return C

# Example input
A = [1, 3, 2, 4]
B = [3, 1, 2, 4]
sol = Solution()
result = sol.findThePrefixCommonArray(A, B)
print(result)
