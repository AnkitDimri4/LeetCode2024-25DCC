
##

---

# **Intuition**

To find the complement of an integer, we need to flip all bits in its binary representation. For this, determine the number of bits required to represent the integer, create a bitmask with all bits set to 1 for this length, and then apply a bitwise XOR operation with the integer to get its complement.

# **Approach**

To compute the complement of an integer **n**, first determine the number of bits required to represent **n** in binary. Create a **bitmask** with all bits set to 1 by shifting 1 left by the number of bits and then subtracting 1. Finally, use bitwise XOR between **n** and the **bitmask** to obtain the complement. This method is efficient with time complexity **O(log n)** and space complexity **O(1)**.

# **Complexity**

- **Time Complexity** $$O(\log n)$$ The operations are proportional to the number of bits in the integer, which is $$\log_2 n$$.
- **Space Complexity** $$O(1)$$ The algorithm uses a constant amount of extra space for variables.
# **Code**

```cpp []
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;  
        int bitmask{1}, temp{n};
        while (temp > 0) {
            bitmask <<= 1;
            temp >>= 1;
        }
        bitmask -= 1;
        return bitmask ^ n;
    }
};
```
---

---
- [🌟 Efficient Solution for "Complement of Base 10 Integer" | C++ | 0ms Beats 100.00% | O(log n)](https://leetcode.com/problems/complement-of-base-10-integer/solutions/5672173/efficient-solution-for-complement-of-base-10-integer-c-0ms-beats-100-00-o-log-n)
---
