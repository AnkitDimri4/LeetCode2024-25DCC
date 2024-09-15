

#
---

# Intuition
The goal is to find the longest substring where each vowel ('a', 'e', 'i', 'o', 'u') appears an even number of times. To achieve this, we use a bitmask to track the parity (even or odd) of each vowel count. A bitmask allows us to efficiently update and query the parity state as we traverse the string.

# Approach
We use a bitmask where each bit represents whether the count of a specific vowel is odd or even. We maintain a prefix XOR array to efficiently compute the parity of vowels over any substring. By checking the prefix XOR values, we determine the longest substring with all even vowel counts.

# Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the string. We traverse the string once to compute the bitmask and once to find the longest valid substring.
- **Space Complexity** $$O(1)$$, as we only use a fixed number of extra variables and a hash map.

# Code

```cpp []
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        int b{0}, maxLen{0};
        m[0] = -1; 
        for (int i{0}; i < s.length(); ++i) {
            switch (s[i]) {
                case 'a': b ^= 1 << 0; break;
                case 'e': b ^= 1 << 1; break;
                case 'i': b ^= 1 << 2; break;
                case 'o': b ^= 1 << 3; break;
                case 'u': b ^= 1 << 4; break;
            }
            if (m.find(b) != m.end()) maxLen = max(maxLen, i - m[b]);
            else  m[b] = i;
        }
        return maxLen;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```

```java []
class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> m = new HashMap<>();
        int b = 0, maxLen = 0;
        m.put(0, -1); 
        for (int i = 0; i < s.length(); ++i) {
            switch (s.charAt(i)) {
                case 'a': b ^= 1 << 0; break;
                case 'e': b ^= 1 << 1; break;
                case 'i': b ^= 1 << 2; break;
                case 'o': b ^= 1 << 3; break;
                case 'u': b ^= 1 << 4; break;
            }
            if (m.containsKey(b)) maxLen = Math.max(maxLen, i - m.get(b));
            else m.put(b, i);
        }
        return maxLen;
    }
}
```

```python []
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        m = {0: -1}
        b, maxLen = 0, 0
        for i, char in enumerate(s):
            if char == 'a': b ^= 1 << 0
            elif char == 'e': b ^= 1 << 1
            elif char == 'i': b ^= 1 << 2
            elif char == 'o': b ^= 1 << 3
            elif char == 'u': b ^= 1 << 4
            if b in m:
                maxLen = max(maxLen, i - m[b])
            else:
                m[b] = i
        return maxLen
```

---
- ![image.png](https://assets.leetcode.com/users/images/3240c739-e907-4968-8e6a-b2e452690fa9_1726378889.4047663.png)
- [Easy Solution | C++ 24ms Beats 84.42% Java Py3 | O(n)](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15)


---