#
---

> # Intuition
To find the k-th bit in the n-th binary string defined by the recursive rules, we can leverage the properties of the string construction. Each string $$ S_n$$ is built from the previous string $$ S_{n-1}$$ and involves a predictable pattern of bits. Instead of constructing the entire string, we can recursively determine the position of the k-th bit based on its location relative to the middle of the string.

> # Approach
We recursively determine the k-th bit's position. If $$ k$$ is less than the midpoint, the k-th bit belongs to $$ S_{n-1}$$. If $$ k$$ is exactly the midpoint, it is '1'. If $$ k$$ is greater than the midpoint, we find the corresponding position in the inverted and reversed part of $$ S_{n-1}$$. The inversion of bits is handled with a simple function.

> # Complexity
- **Time Complexity** $$O(n)$$, where $$ n$$ is the depth of recursion up to the given n, since each level of recursion simplifies the problem size.
- **Space Complexity** $$O(n)$$ for the recursion stack in the worst case.


# Code
```cpp []
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0'; 
        int len = (1 << n) - 1, mid = len / 2 + 1;

        return (k < mid) ? findKthBit(n - 1, k) : (k == mid) ? '1' : invert(findKthBit(n - 1, len - k + 1));
    }
private:
    char invert(char c) {
        return c ^ 1; 
    }
};
```
```java []
class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int len = (1 << n) - 1, mid = len / 2 + 1;
        return (k < mid) ? findKthBit(n - 1, k) : (k == mid) ? '1' : invert(findKthBit(n - 1, len - k + 1));
    }
    private char invert(char c) {
        return (char) ('0' + ('1' - c)); 
    }
}
```
```python3 []
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        length = (1 << n) - 1
        mid = length // 2 + 1
        return self.findKthBit(n - 1, k) if k < mid else '1' if k == mid else self.invert(self.findKthBit(n - 1, length - k + 1))
    def invert(self, c: str) -> str:
        return '1' if c == '0' else '0' 
```
---

> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/cdf91934-0739-446d-abf6-d44176822072_1729325575.5559983.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/40a49894-cb78-4849-beb3-719d2fdb5b95_1729325609.1946704.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/6a02e6b9-517f-4ab6-ac56-6e97ec84548f_1729325592.2549918.png)
[💡 | O(n) | C++ Java Py3 0ms Beats 100.00% | | Easy Solution 🧠| |](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19)

---
