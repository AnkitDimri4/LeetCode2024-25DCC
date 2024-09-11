#
---
# Intuition
To convert the binary representation of start to goal, we need to count the number of bit positions where the two numbers differ. This is equivalent to counting the number of 1's in the XOR of start and goal, as XOR highlights the differing bits (1 for different, 0 for the same).

# Approach
The solution involves XORing start and goal, and then counting the number of 1's in the result. This can be done efficiently by checking each bit using the & operator and shifting the XOR result to the right until all bits are processed.

# Complexity
- **Time complexity** $$𝑂(log 𝑛)$$ where n is the maximum value of start or goal. We process each bit of the XOR result.
- **Space complexity** $$𝑂(1)$$, since we only use a few variables.

# Code
```cpp []
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count{0};
        for (int x = start ^ goal; x; x >>= 1) count += x & 1;
        return count;
    }
};

```
```java []
class Solution {
    public int minBitFlips(int start, int goal) {
        int count = 0;
        for (int x = start ^ goal; x != 0; x >>= 1) {
            count += x & 1;
        }
        return count;
    }
}
```
```python []
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0
        x = start ^ goal
        while x:
            count += x & 1
            x >>= 1
        return count
```

---

- ![image.png](https://assets.leetcode.com/users/images/2768b798-7f04-47a8-8e8f-3a93339a0a55_1726024012.2293599.png)
- [𝑂(log 𝑛) | 0ms Beats 100.00% | Easy Solution](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11)

---