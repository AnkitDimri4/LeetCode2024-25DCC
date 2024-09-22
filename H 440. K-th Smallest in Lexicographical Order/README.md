
#
---
# **Intuition**
The goal is to efficiently find the K-th smallest integer in lexicographical order within the range [1, n]. Instead of generating the entire list of numbers, we use a **depth-first search (DFS) inspired traversal** to directly jump between numbers, counting lexicographical steps between prefixes. This allows us to navigate through the sequence and reach the K-th number without generating the entire list.

# **Approach**
To solve the problem, we initialize the current number as $$1$$ and decrement $$k$$ by 1. For each step, we calculate how many numbers start with the current prefix (lexicographical subtree). If the count is greater than $$k$$, we move to the next level by multiplying the current number by 10. Otherwise, we skip the current subtree, decrement $$k$$ by the number of skipped steps, and move to the next sibling by incrementing the current number. We repeat this until $$k$$ reaches zero, meaning we've found the K-th smallest number. This approach efficiently computes the result in **O(log n)** time by counting numbers at each prefix.

# **Complexity**
- **Time Complexity** $$O(\log n)$$ — Each move calculates steps in a logarithmic fashion based on the number of digits in the number.
- **Space Complexity** $$O(1)$$ — We only use a few extra variables to track the current number and steps.

---
```cpp []
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur{1};
        --k;
        while (k) {
            long steps = count(cur, n);
            if (steps <= k) cur++, k -= steps;
            else cur *= 10, --k;
        }
        return cur;
    }
    long count(long p, long n) {
        long steps{0};
        for (long f = p, l = p; f <= n; f *= 10, l = l * 10 + 9)
            steps += min(n + 1, l + 1) - f;
        return steps;
    }
};
```
```java []
class Solution {
    public int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long steps = countSteps(cur, n);
            if (steps <= k) {
                cur++;
                k -= steps;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
    private long countSteps(long p, long n) {
        long steps = 0;
        for (long f = p, l = p; f <= n; f *= 10, l = l * 10 + 9) {
            steps += Math.min(n + 1, l + 1) - f;
        }
        return steps;
    }
}
```
```python []
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        cur = 1
        k -= 1
        while k > 0:
            steps = self.countSteps(cur, n)
            if steps <= k:
                cur += 1
                k -= steps
            else:
                cur *= 10
                k -= 1
        return cur
    
    def countSteps(self, p: int, n: int) -> int:
        steps = 0
        f, l = p, p
        while f <= n:
            steps += min(n + 1, l + 1) - f
            f *= 10
            l = l * 10 + 9
        return steps
```

---
- ![image.png](https://assets.leetcode.com/users/images/68a96127-21b8-4e98-a83d-d0c71bef6baf_1726968204.9166117.png)
- **Java**
- ![Java.png](https://assets.leetcode.com/users/images/d0e1194b-d785-4e6a-b587-46afcb2545f1_1726968221.6158314.png)
- [O(log n) per Step | DFS Approach | C++ 0ms Beats 100.00% | Java 0ms Beats 100.00% | Python3](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-question&envId=2024-09-22)

---
