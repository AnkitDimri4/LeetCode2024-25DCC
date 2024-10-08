#
---

> # Intuition
To determine the minimum number of swaps required to make a string of brackets balanced, we can keep track of the imbalance as we iterate through the string. The maximum imbalance at any point will indicate how many swaps are needed to balance the string, given that a swap can correct the placement of a closing bracket.

> # Approach
We initialize a counter for the current imbalance and another for the maximum imbalance encountered during the iteration. As we traverse the string, we increase the imbalance for every closing bracket ($$]$$) and decrease it for every opening bracket ($$[$$). The maximum value of the imbalance during this process gives us an idea of how many misplaced closing brackets exist, which translates to the number of swaps required. Finally, since each swap can correct two misplaced brackets, we calculate the required swaps as half the maximum imbalance rounded up.

> # Complexity
- **Time Complexity** $$O(n)$$, where n is the length of the string. We process each character once.
- **Space Complexity** $$O(1)$$, since we only use a few variables for tracking the imbalance.

---

> # Code
```cpp []
class Solution {
public:
    int minSwaps(string s) {
        int imbal{0}, maxImbal{0};
        for (char c : s) maxImbal = max(maxImbal, imbal += c == ']' ? 1 : -1);
        return (maxImbal + 1) / 2;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public int minSwaps(String s) {
        int o = 0, un = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') o++;
            else if (o > 0) o--;
            else un++;
        }
        return (un + 1) / 2;
    }
}
```
```python3 []
class Solution:
    def minSwaps(self, s: str) -> int:
        u = 0  
        for c in s:
            u += 1 if c == '[' else -1 if u > 0 else 0 
        return (u + 1) // 2 
```

---

> **CPP** 
> ![image.png](https://assets.leetcode.com/users/images/f79447e2-2701-4305-af42-b3e8005f4b28_1728357857.6074657.png)
> **Java** 
> ![image.png](https://assets.leetcode.com/users/images/4044aaef-97b1-40b7-ac8d-4c0faaaaf305_1728359547.4504802.png)
> **Python3** 
> ![image.png](https://assets.leetcode.com/users/images/7d81191c-4679-4e05-8d75-f4bf46e1cb9b_1728359597.2837.png)
![💡 | O(n) | C++ 34ms Beats 100.00% | Java 12ms | Python3 166ms Beats 92.90% | Easy Solution 🧠| | ](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/)

---

> ### **Additional Note**
> Note: The simplicity of this approach lies in its linear scan through the string, making it efficient and effective for handling the problem within the given constraints. For instance, in a case like $$]]][[[$$, the maximum imbalance would be 2, indicating that two swaps are necessary to balance the brackets.