#
---

# Intuition
The goal is to arrange the numbers in such a way that they form the largest possible number. Since concatenation order matters, the idea is to compare pairs of numbers as strings and determine which order forms a larger value.

# Approach
First, convert the integers to strings and sort them based on custom rules where the concatenation of two strings (a + b vs b + a) decides their relative order. After sorting, we concatenate the sorted strings to get the final result. If the largest number starts with "0", return "0" to avoid leading zeros. The process efficiently handles the task in a single pass through the list for sorting and concatenation.

# Complexity
- **Time complexity** $$O(n \log n)$$ due to sorting.
- **Space complexity** $$O(n)$$ for storing the string representations.

# Code

```cpp []
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (auto n : nums) s.push_back(to_string(n));
        sort(s.begin(), s.end(), [](string &a, string &b) { return a + b > b + a; });
        string res = accumulate(s.begin(), s.end(), string());
        return res[0] == '0' ? "0" : res;
    }
};
```

```java []
class Solution {
    public String largestNumber(int[] nums) {
        String[] s = new String[nums.length];
        for (int i = 0; i < nums.length; i++) s[i] = String.valueOf(nums[i]);
        Arrays.sort(s, (a, b) -> (b + a).compareTo(a + b));
        String res = String.join("", s);
        return res.charAt(0) == '0' ? "0" : res;
    }
}
```

```python []
class Solution:
    def largestNumber(self, nums):
        s = sorted(map(str, nums), key=lambda x: x*10, reverse=True)
        res = ''.join(s)
        return '0' if res[0] == '0' else res
```

---

![image.png](https://assets.leetcode.com/users/images/e5d70820-d18d-4068-acea-306588fa8d37_1726622140.8704517.png)
- [💡 || Easy Solution | C++ 0ms Beats 100.00% Java Py3 | O(nlogn)](https://leetcode.com/problems/largest-number/description/)

---
