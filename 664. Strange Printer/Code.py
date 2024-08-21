class Solution:
    def __init__(self):
        self.memo = []

    def dp(self, s, i, j):
        if i > j:
            return 0
        if self.memo[i][j] != -1:
            return self.memo[i][j]
        res = self.dp(s, i + 1, j) + 1
        for k in range(i + 1, j + 1):
            if s[k] == s[i]:
                res = min(res, self.dp(s, i, k - 1) + self.dp(s, k + 1, j))
        self.memo[i][j] = res
        return res

    def strangePrinter(self, s: str) -> int:
        n = len(s)
        self.memo = [[-1] * n for _ in range(n)]
        return self.dp(s, 0, n - 1)
