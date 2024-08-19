---
##
---

# Intuition
The problem asks for the minimum number of operations required to get exactly **n** 'A's on a notepad using "Copy All" and "Paste" operations. The key insight is to factorize **n** and use the factors as steps, where each factor indicates the number of times "Paste" is performed after a "Copy All". This method minimizes the operations by exploiting the largest possible chunk of 'A's that can be copied and pasted repeatedly.

# Approach
Start by initializing the step counter. Iterate from **2** to **n**, and for each factor of **n**, reduce **n** by dividing it by that factor and add the factor to the step counter. This process essentially simulates the "Copy All" and "Paste" operations. If **n** is reduced to **1**, the step count represents the minimum number of operations needed.


# Complexity
- **Time Complexity** $$O(\sqrt{n})$$, because we are iterating through factors.
- **Space Complexity** $$O(1)$$, as we are only using a few variables.


# Code
```cpp []
class Solution {
public:
    int minSteps(int n) {
        int s{0};
        for (auto i{2}; i <= n; ++i)
            for (; n % i == 0; s += i, n /= i);
        return s;
    }
};

```

```java []
class Solution {
    public int minSteps(int n) {
        int s = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                s += i;
                n /= i;
            }
        }
        return s;
    }
}
```

```python []
class Solution:
    def minSteps(self, n):
        s = 0
        i = 2
        while i * i <= n:
            while n % i == 0:
                s += i
                n //= i
            i += 1
        if n > 1: 
            s += n
        return s
```

---
**Input**: **n = 3**  
**Output**: **3**

**Explanation** Begin with one 'A'. First, use "Copy All" to copy the single 'A' to the clipboard. Then, perform "Paste" to double the 'A's to two. Finally, perform "Paste" again to triple the 'A's, achieving the target of three 'A's in three steps.

---
![image](https://github.com/user-attachments/assets/b3fb7ff8-b954-48b6-a68a-f87b1c0686dd)

- **[🌟 0ms Beats 100% | O(√n) | Efficient Solution for "2 Keys Keyboard" | C++ | Java | Python](https://leetcode.com/problems/2-keys-keyboard/solutions/5657968/0ms-beats-100-o-n-efficient-solution-for-2-keys-keyboard-c-java-python)**

---

---
