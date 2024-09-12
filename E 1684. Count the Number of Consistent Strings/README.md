#
---
# Intuition
To determine if a string is consistent, check if all characters in the string are within the allowed set of characters. This can be achieved by iterating through each character of the string and verifying its presence in the allowed set.

# Approach
Use a set to store allowed characters for quick lookup. For each string in the **words** array, verify if every character of the string is present in the allowed set. Count the number of strings that meet this criterion.

# Complexity
- **Time Complexity** $$O(n \cdot m)$$ where **n** is the number of words and **m** is the maximum length of a word. We check each character in each word against the allowed set.
- **Space Complexity** $$O(k)$$ where **k** is the number of distinct characters in **allowed** (constant space in practical terms).


# Code
```cpp []
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedSet[26] = {};
        for (char c : allowed) allowedSet[c - 'a'] = true;  
        int count{0};
        for (const auto& word : words) 
            count += all_of(word.begin(), word.end(), [&](char c){ return allowedSet[c - 'a']; });
        return count;
    }
};

```
```java []
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] allowedSet = new boolean[26];
        for (char c : allowed.toCharArray()) allowedSet[c - 'a'] = true;
        int count = 0;
        for (String word : words) {
            boolean consistent = true;
            for (char c : word.toCharArray()) {
                if (!allowedSet[c - 'a']) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
}

```
```python []
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed_set = set(allowed)
        return sum(all(char in allowed_set for char in word) for word in words)
```
---

- ![image.png](https://assets.leetcode.com/users/images/89555adb-9454-42e8-a23e-efee83c59553_1726107054.9225755.png)
- [Easy Solution | O(n⋅m) | 31ms Beats 97.78% | C++Java Py3](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12)

---