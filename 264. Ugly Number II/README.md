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

- **[🌟 0ms Beats 100% | O(n) | Efficient Solution for "Ugly Number II" | DP |C++ | | Java || Python](https://leetcode.com/problems/ugly-number-ii/solutions/5652924/0ms-beats-100-o-n-efficient-solution-for-ugly-number-ii-dp-c-java-python)**

---