#
---

> # Intuition
To achieve the minimum length of the string after removing the substrings "AB" and "CD", we can use a stack-based approach. As we iterate through the string, we can remove pairs of characters that form the specified substrings immediately as we encounter them, allowing for continuous checks as new substrings may form after previous removals.

> # Approach
We initialize an empty stack and iterate through each character in the string. If the current character and the top of the stack form the substrings "AB" or "CD", we pop the stack; otherwise, we push the current character onto the stack. At the end of the iteration, the size of the stack represents the minimum length of the string that cannot be reduced further.

> # Complexity
- **Time Complexity** $$O(n)$$, where n is the length of the string. We process each character once.
- **Space Complexity** $$O(n)$$ in the worst case, where no characters can be removed and all are pushed onto the stack.
---
> # Code
```cpp []
class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && ((c == 'B' && stk.top() == 'A') || (c == 'D' && stk.top() == 'C')))
                stk.pop();
            else 
                stk.push(c);
        }
        return stk.size();
    }
};

```
---

> **CPP** 
> ![image.png](https://assets.leetcode.com/users/images/b3d67e86-ced5-4a23-b50f-2e4f5270114e_1728288250.3363466.png)
[💡 | O(n) | C++ 0ms Beats 100.00% | | Easy Solution 🧠| |](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07) 


---