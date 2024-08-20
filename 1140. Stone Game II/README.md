##

---


# Problem

Alice and Bob are playing a game with piles of stones arranged in a row. Each pile has a positive integer number of stones, and the objective is for Alice and Bob to end with the most stones. Alice starts first, and on each player's turn, they can take all stones from the first X remaining piles, where $$1 \leq X \leq 2M$$, and then update $$M$$ to $$ \text{max}(M, X) $$. The game continues until all stones are taken. The task is to return the maximum number of stones Alice can get, assuming both players play optimally.

# Approach

We use dynamic programming to solve this problem. We define a 2D array **dp** where **dp[i][m]** represents the maximum number of stones the current player can collect from index **i** with **M** equal to **m**. We also maintain a cumulative sum array **sum** to efficiently calculate the total stones in any segment. The goal is to compute **dp[0][1]** which gives the result starting with the first pile and $$M = 1$$. The solution iterates through the piles, updating the **dp** table based on possible moves and the optimal decisions made by the players.

# Complexity

- **Time Complexity** $$O(n^2)$$, as we iterate through the piles and consider possible moves for each state.
- **Space Complexity** $$O(n^2)$$, due to the storage of the **dp** table.

# Code

```cpp []
class Solution {
public:
    int stoneGameII(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> sum(n + 1);
        int i{n - 1};
        while (i >= 0) sum[i] = p[i] + (i + 1 < n ? sum[i + 1] : 0), --i;
        i = n - 1;
        while (i >= 0) {
            int m{1};
            while (m <= n) {
                int x{1};
                while (x <= min(2 * m, n - i)) {
                    dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(m, x)]);
                    ++x;
                }
                ++m;
            }
            --i;
        }
        return dp[0][1];
    }
};

```

```java []
class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[][] dp = new int[n + 1][n + 1];
        int[] sum = new int[n + 1];
        int i = n - 1;
        while (i >= 0) {
            sum[i] = piles[i] + (i + 1 < n ? sum[i + 1] : 0);
            i--;
        }
        i = n - 1;
        while (i >= 0) {
            int m = 1;
            while (m <= n) {
                int x = 1;
                while (x <= Math.min(2 * m, n - i)) {
                    dp[i][m] = Math.max(dp[i][m], sum[i] - dp[i + x][Math.max(m, x)]);
                    x++;
                }
                m++;
            }
            i--;
        }
        return dp[0][1];
    }
}

```
- [Efficient Solution for "Stone Game II" | DP | O(n^2) | Java 20ms | C++](https://leetcode.com/problems/stone-game-ii/solutions/5662866/efficient-solution-for-stone-game-ii-dp-o-n-2-java-20ms-c)
---
---