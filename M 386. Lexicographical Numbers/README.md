#

---
# **Approach**
The problem asks to generate numbers from 1 to $$n$$ in lexicographical order. The best approach is to use a depth-first search (DFS) style traversal. Start from 1 to 9 and then keep expanding by appending digits from 0 to 9 to the current number until it exceeds $$n$$. This make sures we traverse the numbers in lexicographical order.

# **Algorithm**
Start DFS with numbers 1 to 9, and for each number, add it to the result. Expand the number by appending digits from 0 to 9, continuing until the expanded number exceeds $$n$$. This ensures that the numbers are visited in lexicographical order. Once all valid numbers are processed, return the result.

# **Time Complexity**
- **Time Complexity** $$O(n)$$ — The algorithm visits each number from 1 to $$n$$ exactly once.
- **Space Complexity** $$O(1)$$ extra space (apart from the result array), since recursion depth is limited and we only store the result.
---

# **Code**
```cpp []
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i{1}; i < 10; ++i) add(i, n, res);
        return res;
    }
    void add(int x, int n, vector<int>& res) {
        if (x > n) return;
        res.push_back(x);
        for (int i{0}; i < 10 && x * 10 + i <= n; ++i) add(x * 10 + i, n, res);
    }
};
```


```java []
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i < 10; ++i) add(i, n, res);
        return res;
    }
    private void add(int x, int n, List<Integer> res) {
        if (x > n) return;
        res.add(x);
        for (int i = 0; i < 10 && x * 10 + i <= n; ++i) add(x * 10 + i, n, res);
    }
}
```

```python3 []
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        for i in range(1, 10):
            self.add(i, n, res)
        return res
    def add(self, x: int, n: int, res: List[int]):
        if x > n:
            return
        res.append(x)
        for i in range(10):
            if x * 10 + i > n:
                break
            self.add(x * 10 + i, n, res)
```
---
- ![image.png](https://assets.leetcode.com/users/images/8cb8a0b2-4661-43cf-9813-29a4e8a4bcc6_1726936898.7423477.png)
- [O(n) | Easy Solution || DFS | C++ 0ms Beats 100.00% | Java Py3 |](https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21)


---