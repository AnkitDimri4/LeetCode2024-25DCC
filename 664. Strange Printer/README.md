
## 

---

# **Intuition**

The problem requires determining the minimum number of turns needed by a strange printer to print a string, given that it can only print sequences of the same character at a time. The key is to minimize the number of turns by taking advantage of overlapping or repeating characters within the string.

# **Approach**

We use dynamic programming to solve this problem by defining a 2D DP array **dp[i][j]**, where **dp[i][j]** represents the minimum number of turns needed to print the substring from index **i** to **j**. The base case is when **i > j**, requiring 0 turns. To minimize **dp[i][j]**, we explore all possible partitions of the substring and consider if combining the partitions results in fewer turns. If the first and a subsequent character are the same, we can reduce the total number of turns by combining the turns required for both parts.

# **Complexity**

- **Time Complexity** $$O(n^3)$$ The three nested loops each iterate over the length of the string.
- **Space Complexity** $$O(n^2)$$ The DP table requires a 2D array of size **n x n**.

# **Code**

```cpp []
class Solution {
    vector<vector<int>> memo;
    auto dp(string &s, int i, int j) -> int {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        auto res = dp(s, i + 1, j) + 1, k{i + 1};
        while (k <= j) {
            if (s[k] == s[i]) res = min(res, dp(s, i, k - 1) + dp(s, k + 1, j));
            ++k;
        }
        return memo[i][j] = res;
    }
public:
    auto strangePrinter(string s) -> int {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return dp(s, 0, n - 1);
    }
};

```

```python []
class Solution:
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
    def strangePrinter(self, s):
        n = len(s)
        self.memo = [[-1] * n for _ in range(n)]
        return self.dp(s, 0, n - 1)

```

```java []
class Solution {
    private int[][] memo;
    private int dp(String s, int i, int j) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int res = dp(s, i + 1, j) + 1;
        for (int k = i + 1; k <= j; k++) {
            if (s.charAt(k) == s.charAt(i)) {
                res = Math.min(res, dp(s, i, k - 1) + dp(s, k + 1, j));
            }
        }
        return memo[i][j] = res;
    }
    public int strangePrinter(String s) {
        int n = s.length();
        memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }
        return dp(s, 0, n - 1);
    }
}

```

---
- [🌟| O(n^3) | Efficient Solution for "Strange Printer" | DP | C++  | Python | Java](https://leetcode.com/problems/strange-printer/solutions/5667177/o-n-3-efficient-solution-for-strange-printer-dp-c-11ms-python-java)
---

---