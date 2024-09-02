
#
---

## Intuition
We need to keep track of the total amount of chalk each student uses until the remaining chalk is insufficient for the next student. The efficient way to approach this is by first summing up the total chalk usage in one full round. Then, instead of repeatedly subtracting the chalk for every student until we run out, we can take advantage of the modulus operation to significantly reduce the number of operations needed.

## Approach
First, calculate the total chalk used by all students in one complete round. Then, reduce $$k$$ using the modulus operation **(k %= total)** to determine the effective chalk count after accounting for all full rounds of distribution. Finally, traverse the chalk array, subtracting each student's chalk usage from $$k$$ until the remaining chalk is insufficient for a student. This approach efficiently minimizes unnecessary iterations, making it optimal even for large inputs.

## Complexity
- **Time Complexity** The time complexity is $$O(n)$$ due to the initial summation and the subsequent traversal.
- **Space Complexity** The space complexity is $$O(1)$$ since we're only using a few extra variables.

---

```cpp []
class Solution {
public:
    int chalkReplacer(vector<int>& ch, int k) {
        long long total{0};
        for (int c : ch) total += c;
        k %= total;
        int i{0};
        while (k >= ch[i]) k -= ch[i++];
        return i;
    }
};
```

```java []
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long total = 0;
        for (int c : chalk) total += c;
        k %= total;
        int i = 0;
        while (k >= chalk[i]) k -= chalk[i++];
        return i;
    }
}
```

```python []
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total = sum(chalk)
        k %= total
        i = 0
        while k >= chalk[i]:
            k -= chalk[i]
            i += 1
        return i
```
![image.png](https://assets.leetcode.com/users/images/02c66f31-98d4-4071-bbbe-35bd5367b756_1725247831.2443202.png)

---
- [🌟| Efficient Solution | 76ms Beats 95.27% | C++ Java Py3 | O(n) |](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/)
---