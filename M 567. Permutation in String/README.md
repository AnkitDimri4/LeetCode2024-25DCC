#

---

> # Intuition
We are asked to check if any permutation of string $$s1$$ exists as a substring within $$s2$$. This problem can be solved by using the sliding window technique along with frequency arrays. By maintaining a frequency count of characters in both strings, we can compare them efficiently. If the frequency arrays match, we know that one of the permutations of $$s1$$ is a substring in $$s2$$.

> # Approach
If $$s1$$ is longer than $$s2$$, return $$false$$ since a permutation is impossible. To check if any substring of $$s2$$ is a permutation of $$s1$$, use two frequency arrays $$f1$$ and $$f2$$ (both size 26). $$f1$$ tracks the frequency of characters in $$s1$$, while $$f2$$ tracks the frequency of characters in the current sliding window of $$s2$$. Initialize both arrays by processing the first window in $$s2$$ (of length $$s1$$). Then slide the window across $$s2$$, updating $$f2$$ by adding the new character and removing the one that exits. After each slide, compare $$f1$$ and $$f2$$. If they match, return $$true$$; otherwise, return $$false$$.


> # Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of $$s2$$. We traverse $$s2$$ with a sliding window and compare frequency arrays.
- **Space Complexity** $$O(1)$$, since the size of the frequency arrays is fixed (26 elements).
---
> # Code
```cpp []
class Solution {
public:
    bool checkInclusion(string p, string s) {
        if (p.size() > s.size()) return false;
        vector<int> f1(26), f2(26);
        for (int i{0}; i < p.size(); ++i) f1[p[i] - 'a']++, f2[s[i] - 'a']++;
        for (int i = p.size(); i < s.size(); ++i) {
            if (f1 == f2) return true;
            f2[s[i] - 'a']++, f2[s[i - p.size()] - 'a']--;
        }
        return f1 == f2;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
class Solution {
    public boolean checkInclusion(String p, String s) {
        if (p.length() > s.length()) return false;
        int[] f1 = new int[26], f2 = new int[26];
        for (int i = 0; i < p.length(); i++) {
            f1[p.charAt(i) - 'a']++;
            f2[s.charAt(i) - 'a']++;
        }
        for (int i = p.length(); i < s.length(); i++) {
            if (Arrays.equals(f1, f2)) return true;
            f2[s.charAt(i) - 'a']++;
            f2[s.charAt(i - p.length()) - 'a']--;
        }
        return Arrays.equals(f1, f2);
    }
}
```
```python3 []
class Solution:
    def checkInclusion(self, p: str, s: str) -> bool:
        if len(p) > len(s): return False
        f1, f2 = [0] * 26, [0] * 26
        for i in range(len(p)):
            f1[ord(p[i]) - ord('a')] += 1
            f2[ord(s[i]) - ord('a')] += 1
        for i in range(len(p), len(s)):
            if f1 == f2: return True
            f2[ord(s[i]) - ord('a')] += 1
            f2[ord(s[i - len(p)]) - ord('a')] -= 1
        return f1 == f2
```
---

> **CPP** 
> ![image.png](https://assets.leetcode.com/users/images/c5292e50-df42-4d3c-8f65-7ba282f39e0c_1728098931.8001873.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/8c1e6792-98fe-4c49-99c4-b77f3b7bb7d9_1728098998.3647795.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/5dfede78-09f9-44fa-b097-34477bcc33d0_1728098971.796943.png)
[💡| O(n) | C++ 3ms Beats 94.61% | Java 7ms | Py3 47ms | Sliding Window + Frequency Array |](https://leetcode.com/problems/permutation-in-string/description/?envType=daily-question&envId=2024-10-05)

---

> ### Additional Notes
> In each of the solutions, we use a frequency array to keep track of character counts. Comparing the frequency arrays after each window slide lets us check if a permutation of $$s1$$ exists as a substring in $$s2$$.
> This solution works efficiently with an $$O(n)$$ time complexity, making it scalable even for the upper input limits.

---
