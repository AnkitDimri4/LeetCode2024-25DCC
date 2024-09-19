#
---

# Intuition
The goal is to compute all possible results from different ways of adding parentheses in the given expression. This problem can be approached using divide and conquer. Each operator $$+$$, $$-$$, or $$*$$ splits the expression into two parts, and we recursively calculate all possible results for each part. The final result is obtained by combining these results using the current operator.
# Approach
Recursively divide the expression at each operator ($$+$$, $$-$$, $$*$$), solving the left and right parts independently. If the expression is purely a number, return it directly. For each operator found, compute the results of the left and right sub-expressions and combine them using the current operator. Repeat this process for every operator in the expression, collecting all possible results.

# Complexity
- **Time Complexity** $$O(2^n)$$ due to recursive splitting of the expression based on operators.
- **Space Complexity** $$O(n)$$ for the recursion stack, where $$n$$ is the length of the expression.


# Code
---
```cpp []
class Solution {
public:
    vector<int> diffWaysToCompute(string expr) {
        vector<int> res;
        if (all_of(expr.begin(), expr.end(), ::isdigit)) return {stoi(expr)};
        for (int i{0}; i < expr.size(); ++i) {
            if (ispunct(expr[i])) {
                auto left = diffWaysToCompute(expr.substr(0, i));
                auto right = diffWaysToCompute(expr.substr(i + 1));
                for (int l : left) 
                    for (int r : right) 
                        res.push_back(expr[i] == '+' ? l + r : expr[i] == '-' ? l - r : l * r);
            }
        }
        return res;
    }
};
```
```java []
class Solution {
    public List<Integer> diffWaysToCompute(String expr) {
        List<Integer> res = new ArrayList<>();
        if (expr.chars().allMatch(Character::isDigit)) {
            res.add(Integer.parseInt(expr));
            return res;
        }
        for (int i = 0; i < expr.length(); ++i) {
            if (expr.charAt(i) == '+' || expr.charAt(i) == '-' || expr.charAt(i) == '*') {
                List<Integer> left = diffWaysToCompute(expr.substring(0, i));
                List<Integer> right = diffWaysToCompute(expr.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        res.add(expr.charAt(i) == '+' ? l + r : expr.charAt(i) == '-' ? l - r : l * r);
                    }
                }
            }
        }
        return res;
    }
}
```
```python3 []
class Solution:
    def diffWaysToCompute(self, expr: str) -> List[int]:
        if expr.isdigit():
            return [int(expr)]
        res = []
        for i, c in enumerate(expr):
            if c in "+-*":
                left = self.diffWaysToCompute(expr[:i])
                right = self.diffWaysToCompute(expr[i + 1:])
                res.extend(l + r if c == '+' else l - r if c == '-' else l * r for l in left for r in right)
        return res

```
---
- ![image.png](https://assets.leetcode.com/users/images/fc35ac9a-0892-4862-9955-60b701e1c4eb_1726765369.4739575.png)
- [💡 Efficient Divide and Conquer Solution for Different Ways to Add Parentheses | O(2^n) |](https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19)

---