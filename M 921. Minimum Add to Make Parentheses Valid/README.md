
#
---

> # Intuition
To determine the minimum number of insertions required to make the parentheses string valid, we need to track the number of unmatched opening and closing parentheses. As we traverse the string, we increment counts based on whether the current character is an opening or closing parenthesis. When a closing parenthesis is found but no opening parenthesis is available to match, we increase the count of unmatched closing parentheses. At the end, the total unmatched parentheses are the result of adding unmatched opening and closing parentheses.

> # Approach
We initialize two counters: one for unmatched opening parentheses and another for unmatched closing parentheses. As we traverse the string, we increment the opening counter when we find an opening parenthesis. When we find a closing parenthesis, if there are unmatched opening parentheses, we decrement the opening counter (indicating a match). Otherwise, we increment the closing counter (indicating an unmatched closing parenthesis). The result is the sum of unmatched opening and closing parentheses.

> # Complexity
- **Time Complexity** $$O(n)$$, where n is the length of the string. We process each character once.
- **Space Complexity** $$O(1)$$, since we only use a few variables for tracking counts.

---

> # Code
```cpp []
class Solution {
public:
    int minAddToMakeValid(string s) {
        int o{0}, c{0};
        for (char ch : s) ch == '(' ? ++o : o ? --o : ++c;
        return o + c;
    }
};
```
```Java []
class Solution {
    public int minAddToMakeValid(String s) {
        int o = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                o++;
            } else if (o > 0) {
                o--;
            } else {
                c++;
            }
        }
        return o + c;
    }
}
```
```python3 []
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        o = c = 0
        for ch in s:
            if ch == '(':
                o += 1
            elif o > 0:
                o -= 1
            else:
                c += 1
        return o + c
```

---

> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/7a42cf00-0afc-43aa-95f0-3c8f96432dcd_1728444165.6912827.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/495dbd74-1b8f-450c-ac06-514b4e25ee6c_1728444890.0970275.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/672702f0-2289-4f76-84e8-dd369af3e200_1728444872.0458703.png)
[💡| O(n) | C++ 0ms Beats 100.00% | Easy Solution🧠| Py3 23ms Beats 98.69% | Java 0ms Beats 100.00% |](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

---

> ### Additional Notes
> Note : The approach is highly efficient with a time complexity of $$𝑂(𝑛)$$, making a single pass through the string, and constant space. This makes sure optimal performance for the given constraints.

---
