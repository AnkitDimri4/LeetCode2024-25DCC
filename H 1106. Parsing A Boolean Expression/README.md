#
---

> # Intuition
The problem requires evaluating a boolean expression represented in a structured format. The expressions can be nested and utilize operators like NOT ($$!$$), AND ($$&$$), ![image](https://github.com/user-attachments/assets/386b2009-51a2-47cb-9673-ff38c47b1c04)
 and OR ($$|$$). The solution involves utilizing a **stack** to manage the evaluation of sub-expressions effectively.

> # Approach
We traverse the expression character by character, using a stack to handle the operators and their operands. When encountering a closing parenthesis $$)$$, we pop from the stack until we reach the matching opening parenthesis $$($$, evaluate the contained sub-expressions based on the operator, and push the result back onto the stack. This continues until the entire expression is evaluated, and the final result is determined by the value remaining in the stack.

> # Complexity
- **Time Complexity** $$O(n)$$, where n is the length of the expression, since we process each character once.
- **Space Complexity** $$O(n)$$ for the stack, which can hold up to n/2 characters in the worst case due to nested expressions.


# Code
```cpp []
class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> stk;
        for (char ch : exp) {
            if (ch == ',') continue;
            if (ch == ')') {
                bool t = false, f = false;
                while (stk.top() != '(') {
                    t |= stk.top() == 't';
                    f |= stk.top() == 'f';
                    stk.pop();
                }
                stk.pop(); 
                char op = stk.top(); stk.pop();
                stk.push(op == '!' ? (t ? 'f' : 't') : (op == '&' ? (f ? 'f' : 't') : (t ? 't' : 'f')));
            } else stk.push(ch);
        }
        return stk.top() == 't';
    }
};

auto _ = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```python3 []
class Solution:
    def parseBoolExpr(self, exp: str) -> bool:
        stk = []
        for ch in exp:
            if ch == ',': continue
            if ch == ')':
                t = f = False
                while stk[-1] != '(':
                    top = stk.pop()
                    t |= top == 't'
                    f |= top == 'f'
                stk.pop()  
                op = stk.pop()  
                stk.append('t' if (op == '|' and t) or (op == '&' and not f) else 'f')
                if op == '!': stk[-1] = 'f' if t else 't'
            else: stk.append(ch)
        return stk[-1] == 't'
solution = Solution()
print(solution.parseBoolExpr("&(t,t,t)"))  
print(solution.parseBoolExpr("&(|(f))")) 
print(solution.parseBoolExpr("|(f,f,f,t)"))  
print(solution.parseBoolExpr("!(&(f,t))"))
```
```Java []
class Solution {
    int idx = 0;
    public boolean parseBoolExpr(String e) {
        char op = e.charAt(idx++);
        if (op == 't') return true; 
        if (op == 'f') return false; 
        idx++; 
        List<Boolean> vals = new ArrayList<>();
        while (e.charAt(idx) != ')') {
            if (e.charAt(idx) != ',') vals.add(parseBoolExpr(e)); 
            else idx++; 
        }
        idx++;
        return op == '!' ? !vals.get(0) : op == '&' ? vals.stream().allMatch(v -> v) : vals.stream().anyMatch(v -> v);
    }
}
```

---


> **CPP**
> ![Screenshot 2024-10-20 070653.png](https://assets.leetcode.com/users/images/2fcc3548-4ebb-4554-9478-a7579912ca4a_1729389502.3452446.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/0bbcdbf3-9ff9-48b3-88b7-eed906e14c6f_1729389550.5815127.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/426ab22f-699f-4dc9-ae61-72258e200ff3_1729389535.872623.png)

[💡 | O(n) | C++ 0ms Beats 100.00% || Py3 11ms Beats 100.00% | Java 7ms || Easy Solution 🧠||](https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20)

---

> ### Additional Note
> **Note**: This approach effectively handles nested boolean expressions using stacks, allowing for efficient evaluation and handling of complex structures.

---
