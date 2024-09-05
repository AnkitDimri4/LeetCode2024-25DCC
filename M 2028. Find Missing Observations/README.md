#

---

# Intuition and Approach
To find the missing observations, calculate the total sum required for all the rolls by multiplying the mean by the total number of rolls $$n + m$$. Subtract the sum of the given rolls from this total to get the sum for the missing rolls. If this sum is outside the valid dice range (less than $$n$$ or greater than $$6 \times n$$), return an empty array as it's impossible to achieve the target mean. Otherwise, distribute the missing sum evenly across $$n$$ missing rolls, and adjust for any remainder by incrementing some rolls to handle the leftover.

# Complexity
- **Time Complexity** $$O(m + n)$$ — where $$m$$ is the length of the given rolls and $$n$$ is the number of missing rolls.
- **Space Complexity** $$O(n)$$ — as we create an array of size $$n$$ for the missing rolls.

---


```cpp []
class Solution {
public:
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int total = mean * (n + r.size()), missSum = total - accumulate(r.begin(), r.end(), 0);
        if (missSum < n || missSum > 6 * n) return {};
        vector<int> res(n, missSum / n);
        int rem = missSum % n;
        for (int i = 0; i < rem; ++i) res[i]++;
        return res;
    }
};
```

```java []
import java.util.Arrays;
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int total = mean * (n + rolls.length);
        int missSum = total - Arrays.stream(rolls).sum(); 
        if (missSum < n || missSum > 6 * n) return new int[0]; 
        int[] res = new int[n];
        Arrays.fill(res, missSum / n);
        int rem = missSum % n; 
        for (int i = 0; i < rem; i++) res[i]++;
        return res;
    }
}
```

```python []
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        total = mean * (n + len(rolls))
        miss_sum = total - sum(rolls)
        if miss_sum < n or miss_sum > 6 * n:
            return []
        res = [miss_sum // n] * n
        for i in range(miss_sum % n):
            res[i] += 1
        return res
```

- ![image.png](https://assets.leetcode.com/users/images/4d5f8ebb-de30-4573-a05c-9f98d616996d_1725507019.5369923.png)

- [Easy Solution || 86ms Beats 87.50% | O(m+n) | C++ Py3 Java |](https://leetcode.com/problems/find-missing-observations/description/)
---
