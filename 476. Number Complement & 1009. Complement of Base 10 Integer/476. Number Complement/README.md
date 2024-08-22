
##
---
# Intuition

The problem requires finding the complement of a given integer. The complement is obtained by flipping all bits in the binary representation of the number.

# **Approach**

To find the complement of an integer **num**, first determine the number of bits needed to represent **num** in binary. Create a bitmask with all bits set to 1, matching this length. Apply a bitwise NOT operation to **num**, and then use bitwise AND with the bitmask to obtain the complement. This method efficiently computes the result by leveraging bitwise operations.

# Complexity
- **Time Complexity** $$O(\log n)$$ The operations are based on the number of bits in the integer.
- **Space Complexity** $$O(1)$$ Only a few additional variables are used.


# Code
```cpp []
class Solution {
public:
    int findComplement(int num) {
        int number = num,bitmask = pow(2, ceil((double)log2(number))) - 1;
        return (~number) & bitmask;
    }
};
```
---
- [🌟 Efficient Solution for "Number Complement" | C++ | 0ms Beats 100.00% | O(log n)](https://leetcode.com/problems/number-complement/solutions/5672071/efficient-solution-for-number-complement-c-0ms-beats-100-00-o-log-n)
---