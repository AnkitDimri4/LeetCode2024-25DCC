#
---


# **Intuition**
The problem requires adding and subtracting fractions within a given string expression. The key is to process each fraction one by one, maintaining a running total as you move through the string.

# **Approach**
To solve this problem, initialize the numerator as 0 and the denominator as 1. As you parse through each fraction in the expression, update the running total by computing the sum of the current fraction and the total so far. Normalize the result by dividing both the numerator and the denominator by their greatest common divisor (GCD) to simplify the fraction. Continue this process until all fractions are processed. The final result is the simplified fraction of the total sum.

# **Complexity**
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the expression, as each character in the expression is processed once.
- **Space Complexity** $$O(1)$$, only a few additional variables are used.

# **Code**

```cpp []
class Solution {
public:
    string fractionAddition(string expr) {
        int num{0}, den{1}, n, d;
        char slash;
        for (istringstream in(expr); in >> n >> slash >> d; ) {
            num = num * d + n * den;
            den *= d;
            int gcd = std::gcd(abs(num), den);
            num /= gcd;
            den /= gcd;
        }
        return to_string(num) + "/" + to_string(den);
    }
};
```

```java []
class Solution {
    public String fractionAddition(String expr) {
        int num = 0, den = 1;
        for (String s : expr.split("(?=[+-])")) {
            int gcd = gcd(Math.abs(num * Integer.parseInt(s.split("/")[1]) + Integer.parseInt(s.split("/")[0]) * den), den * Integer.parseInt(s.split("/")[1]));
            num = (num * Integer.parseInt(s.split("/")[1]) + Integer.parseInt(s.split("/")[0]) * den) / gcd;
            den = (den * Integer.parseInt(s.split("/")[1])) / gcd;
        }
        return num + "/" + den;
    }
    
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```
```python []
class Solution:
    def fractionAddition(self, expr: str) -> str:
        from math import gcd
        num, den = 0, 1
        import re
        for n, d in re.findall(r'([+-]?\d+)/(\d+)', expr):
            n, d = int(n), int(d)
            num = num * d + n * den
            den *= d
            g = gcd(abs(num), den)
            num //= g
            den //= g
        return f'{num}/{den}'
```
---

- [🌟 | C++ | Java | Python3 | 0ms Beats 100.00% | O(n) | Fraction Addition and Subtraction | ](https://leetcode.com/problems/fraction-addition-and-subtraction/solutions/5677284/c-java-python3-0ms-beats-100-00-o-n-fraction-addition-and-subtraction)

---