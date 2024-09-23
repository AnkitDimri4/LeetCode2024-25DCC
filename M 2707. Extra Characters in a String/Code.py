from typing import List

class Solution:
    def minExtraChar(self, s: str, d: List[str]) -> int:
        dict_set = set(d)
        dp = [len(s)] * (len(s) + 1)
        dp[0] = 0  
        for i in range(1, len(s) + 1):
            dp[i] = dp[i - 1] + 1  
            for j in range(i):
                if s[j:i] in dict_set: 
                    dp[i] = min(dp[i], dp[j])
        return dp[len(s)]

if __name__ == "__main__":
    s = "leetscode"
    dictionary = ["leet", "code", "leetcode"]
    sol = Solution()
    print("Minimum extra characters:", sol.minExtraChar(s, dictionary))
