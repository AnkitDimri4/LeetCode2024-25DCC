#
---
# Intuition
To solve the problem efficiently, we use a dynamic programming (DP) approach. The key idea is to try and match substrings of the given string $$s$$ with words in the dictionary. If a match is found, we skip those characters, otherwise, they count as extra characters. Our goal is to minimize these extra characters left.

# Approach
We initialize a DP array $$dp$$ where $$dp[i]$$ represents the minimum number of extra characters up to index $$i$$ in the string. For each character in the string, we assume it is an extra character by default, so we set $$dp[i] = dp[i-1] + 1$$. Then, for each word in the dictionary, we check if it fits at the current position. If it does, we update $$dp[i]$$ to take the minimum between the current value and the value at the start of the matching substring.

# Complexity
- **Time Complexity** $$O(n \times m)$$, where $$n$$ is the length of the string $$s$$, and $$m$$ is the total length of all dictionary words.
- **Space Complexity** $$O(n)$$, for the DP array storing results for each character in the string.
---
# Code
```cpp []
class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size(), m;
        vector<int> dp(n + 1);
        for (int i{1}; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; 
            for (const string& word : d) {
                m = word.size();
                if (i >= m && s.substr(i - m, m) == word) dp[i] = min(dp[i], dp[i - m]);
            }
        }
        return dp[n];
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public int minExtraChar(String s, String[] d) {
        Set<String> dict = new HashSet<>();
        for (String word : d) {
            dict.add(word);
        }
        int[] dp = new int[s.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            dp[i] = s.length(); 
        }
        dp[0] = 0; 
        for (int i = 1; i <= s.length(); i++) {
            dp[i] = dp[i - 1] + 1;  
            for (int j = 0; j < i; j++) {
                if (dict.contains(s.substring(j, i))) 
                    dp[i] = Math.min(dp[i], dp[j]);  
            }
        }
        return dp[s.length()]; 
    }
}
```
```python3 []
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
```


---

- ![image.png](https://assets.leetcode.com/users/images/734b75c7-5ef2-4015-8da9-8f84772a8d63_1727058109.8440282.png)
- [O(n×m) | DP Easy Solution || C++ 23ms Beats 100.00% Java Python3 |](https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-09-23)

---