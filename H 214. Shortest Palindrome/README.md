#
---
# Intuition
To solve the problem efficiently, we leverage **KMP (Knuth-Morris-Pratt)** algorithm's prefix function. By constructing a modified string, which consists of the original string and its reverse, we can find the longest prefix of the original string that is also a suffix. This information allows us to determine the shortest palindrome by appending the minimum required characters in front of the original string.

# Approach
First, reverse the given string and concatenate it with the original string using a delimiter (e.g., $$"#"$$) to avoid overlap between the two. Next, compute the **KMP prefix array** for the concatenated string to find the longest palindromic prefix. The last value of this array tells us the length of the longest prefix that matches a suffix in the original string. Using this, we append the necessary characters from the reversed string to the front of the original string, forming the shortest palindrome.

# Complexity
- **Time Complexity** $$O(n)$$ where $$n$$ is the length of the string. Both computing the reverse and building the KMP table take linear time.
- **Space Complexity** $$O(n)$$ for storing the reverse string and the KMP table.

# Code
```cpp []
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;
        vector<int> kmp(comb.size());
        for (int i{1}, j{0}; i < comb.size(); ++i) {
            j = kmp[i - 1];
            while (j > 0 && comb[i] != comb[j]) j = kmp[j - 1];
            if (comb[i] == comb[j]) ++j;
            kmp[i] = j;
        }
        return rev.substr(0, s.size() - kmp.back()) + s;
    }
};
```
```java []
class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String comb = s + "#" + rev;
        int[] kmp = new int[comb.length()];
        for (int i = 1, j = 0; i < comb.length(); ++i) {
            j = kmp[i - 1];
            while (j > 0 && comb.charAt(i) != comb.charAt(j)) j = kmp[j - 1];
            if (comb.charAt(i) == comb.charAt(j)) ++j;
            kmp[i] = j;
        }
        return rev.substring(0, s.length() - kmp[kmp.length - 1]) + s;
    }
}
```
```python3 []
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        comb = s + "#" + rev
        kmp = [0] * len(comb)
        j = 0
        for i in range(1, len(comb)):
            j = kmp[i - 1]
            while j > 0 and comb[i] != comb[j]:
                j = kmp[j - 1]
            if comb[i] == comb[j]:
                j += 1
            kmp[i] = j
        return rev[:len(s) - kmp[-1]] + s
```

---

- 
![image.png](https://assets.leetcode.com/users/images/70cee062-2dc8-4694-93fd-e0e318720e45_1726803102.7627122.png)

- ![Designer.png](https://assets.leetcode.com/users/images/5395952a-4267-4b87-b81f-f28780669704_1726803172.327018.png)
- [O(n) | Easy Solution || KMP (Knuth-Morris-Pratt) | C++ 0ms Beats 100.00% | Java Py3 |](https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20)

---
