
## 

---
# **Intuition**

The problem involves finding the nth ugly number, where an ugly number is a positive integer whose only prime factors are 2, 3, or 5. Use a dynamic programming approach to generate ugly numbers sequentially, ensuring that each new ugly number is derived from previous ones by multiplying with 2, 3, or 5.


# **Approach**
Use a dynamic programming array to store the first n ugly numbers. Track three indices for the multiples of 2, 3, and 5. At each step, select the smallest value among these multiples as the next ugly number, and advance the respective index. This approach guarantees that the numbers are produced in increasing order without duplicates.

### **Complexity**
- **Time Complexity** \(O(n)\), as we generate the ugly numbers sequentially up to the nth number.
- **Space Complexity** \(O(n)\), since we store the first n ugly numbers.

### **Code**

```cpp []
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> u(n, 1);
        for(auto i{1}, i2{0}, i3{0}, i5{0}; i < n; ++i) {
            u[i] = min({u[i2] * 2, u[i3] * 3, u[i5] * 5});
            i2 += (u[i] == u[i2] * 2);
            i3 += (u[i] == u[i3] * 3);
            i5 += (u[i] == u[i5] * 5);
        }
        return u.back();
    }
};
```
```java []
class Solution {
    public int nthUglyNumber(int n) {
        int[] u = new int[n];
        u[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            u[i] = Math.min(u[i2] * 2, Math.min(u[i3] * 3, u[i5] * 5));
            if (u[i] == u[i2] * 2) i2++;
            if (u[i] == u[i3] * 3) i3++;
            if (u[i] == u[i5] * 5) i5++;
        }
        return u[n - 1];
    }
}
```

```python []
class Solution:
    def nthUglyNumber(self, n):
        u = [1] * n
        i2 = i3 = i5 = 0
        for i in range(1, n):
            u[i] = min(u[i2] * 2, u[i3] * 3, u[i5] * 5)
            if u[i] == u[i2] * 2:
                i2 += 1
            if u[i] == u[i3] * 3:
                i3 += 1
            if u[i] == u[i5] * 5:
                i5 += 1
        return u[-1]

```

- **[Python Beats 100% | Java 12ms | C++ 151ms Beats 97.28% | DP | "Maximum Number of Points with Cost"](https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/5647965/python-beats-100-java-12ms-c-151ms-beats-97-28-dp-maximum-number-of-points-with-cost)**

---
=======
# LeetCode2024DCC
Solutions and explanations for LeetCode's Daily Coding Challenges in 2024.

---