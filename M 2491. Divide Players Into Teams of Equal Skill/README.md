#

---

> # Intuition
To form teams of players with equal chemistry, we need to make sure that every pair of players has a combined skill level that is constant across all teams. By sorting the array of skill levels and pairing the smallest with the largest, we can easily verify if such teams can be formed. If any pair does not satisfy this, it's impossible to form the teams.

> # Approach
First, sort the array of player skills. Calculate the target team skill sum by dividing the total skill sum by half the number of players. Then, iterate through the sorted skills, pairing the first and last, second and second-last, and so on. If the sum of any pair does not match the target, return -1. If valid, calculate the total chemistry as the product of the skill values for each valid pair.

> # Complexity
- **Time Complexity** Sorting takes $$O(n log n)$$, where $$n$$ is the number of players.  
  - Accumulation and verification of pairs is $$O(n)$$.  
  Thus, the overall complexity is $$O(n log n)$$.
  
- **Space Complexity** $$O(1)$$ extra space apart from input and output.

> # Code
```cpp []
class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(), s.end());
        long long chem{0}, total = accumulate(s.begin(), s.end(), 0LL) / (s.size() / 2);
        for (int i{0}, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] + s[j] != total) return -1;
            chem += 1LL * s[i] * s[j];
        }
        return chem;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        long total = 0, chem = 0;
        for (int x : skill) total += x;
        total /= (skill.length / 2);
        int i = 0, j = skill.length - 1;
        while (i < j) {
            if (skill[i] + skill[j] != total) return -1;
            chem += (long) skill[i] * skill[j];
            i++;
            j--;
        }
        return chem;
    }
}
```
```python3 []
class Solution:
    def dividePlayers(self, s: List[int]) -> int:
        t, c, r = 2 * sum(s) // len(s), Counter(s), 0
        for x, y in c.items():
            if y != c[t - x]: return -1
            r += x * (t - x) * y
        return r // 2
```

> **CPP** 
> > ![image.png](https://assets.leetcode.com/users/images/3ae9b1c9-9a3e-487d-b612-b19ec41eaf06_1728012434.9581645.png)

> **Java**
> > ![image.png](https://assets.leetcode.com/users/images/6bdb7fbf-a66b-4bd2-9834-e378d61d4d18_1728012473.7350414.png)

> [💡 | O(n) | C++ 33ms Beats 99.80% | Java 12ms Beats 92.19% | Python3 369ms Beats 97.34% |](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04)

---

> ## **Additional Note**
> The C++ solution provides a highly optimized implementation using sorting and two-pointer techniques. The Python implementation uses a counter for verification and offers a different approach to solving the problem, albeit with higher runtime. The Java code achieves a good balance between readability and performance with the use of straightforward sorting and iteration.

---

