#
---
> # Intuition
The problem asks to find the maximum possible number by swapping two digits at most once. To achieve this, we can utilize the fact that swapping a smaller digit with the largest available digit that occurs later in the number gives the maximum result.

> # Approach
The approach involves converting the number to a string for easy digit manipulation, then tracking the last occurrence of each digit (0-9). As we iterate through the digits, we check if a larger digit appears later in the number. If found, we swap the current digit with the largest possible one and return the result immediately. If no beneficial swap is possible, we simply return the original number. This makes sure we maximize the number with at most one swap.

> # Complexity
- **Time Complexity**: $$O(n)$$, where n is the number of digits in the number.
- **Space Complexity**: $$O(1)$$ (since the auxiliary space used by the array **last** is constant).

---

# Code
```cpp []
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> last(10);
        for (int i{0}; i < s.size(); ++i)
            last[s[i] - '0'] = i;
        for (int i{0}; i < s.size(); ++i)
            for (int d{9}; d > s[i] - '0'; --d)
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
        return num;
    }
};
```
```java []
class Solution {
    public int maximumSwap(int num) {
        char[] s = Integer.toString(num).toCharArray();
        int[] last = new int[10];
        for (int i = 0; i < s.length; i++) 
            last[s[i] - '0'] = i;
        for (int i = 0; i < s.length; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    char temp = s[i];
                    s[i] = s[last[d]];
                    s[last[d]] = temp;
                    return Integer.parseInt(new String(s));
                }
            }
        }
        return num;
    }
}
```
---
> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/95067633-11a0-48f4-9529-7caa3e5bc1c7_1729154566.3532245.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/c78248bc-a99d-4e8c-b268-11b00ec9132d_1729154542.084402.png)
[💡 | O(n) | C++ 0ms Beats 100.00% | Java 0ms Beats 100.00% | Easy Solution 🧠| |](https://leetcode.com/problems/maximum-swap/description/)

---