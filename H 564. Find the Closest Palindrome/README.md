# 
---
# Intuition
To find the closest palindrome to a given number, consider generating potential palindrome candidates by modifying the prefix of the number. This approach involves finding palindromes of the same length or one length more or less than the given number. By comparing these candidates, we can identify the closest palindrome.

# Approach
To solve the problem of finding the closest palindrome, first generate potential palindrome candidates by modifying the prefix of the given number, including by incrementing or decrementing it and then mirroring it to form a full palindrome. Next, compare these candidates to the original number by evaluating the absolute differences between them. Track the closest palindrome that is not the original number, making sure that the smallest absolute difference determines the result.

# Complexity
- **Time complexity** $$O(n)$$, where $$n$$ is the length of the number string. This includes generating and comparing the potential palindrome candidates.
- **Space complexity** $$O(n)$$, due to the storage of palindrome candidates and intermediate results.

# Code
```cpp []
class Solution {
public:
    string nearestPalindromic(string s) {
        long n = stol(s), res = -1;
        vector<long> c = {long(pow(10, s.size() - 1)) - 1, long(pow(10, s.size())) + 1};
        string p = s.substr(0, (s.size() + 1) / 2);
        auto i = -1;
        while (i <= 1) {
            string pal = to_string(stol(p) + i++);
            string r = pal.substr(0, s.size() / 2);
            reverse(r.begin(), r.end());
            c.push_back(stol(pal + r));
        }
        i = 0;
        while (i < c.size()) {
            long x = c[i++];
            if (x != n && (res == -1 || abs(x - n) < abs(res - n) || (abs(x - n) == abs(res - n) && x < res))) {
                res = x;
            }
        }
        return to_string(res);
    }
};
```
```java []
class Solution {
    public String nearestPalindromic(String s) {
        long num = Long.parseLong(s);
        long[] c = {
            (long) Math.pow(10, s.length() - 1) - 1,
            (long) Math.pow(10, s.length()) + 1
        };
        String p = s.substring(0, (s.length() + 1) / 2);
        int i = -1;
        while (i <= 1) {
            String pStr = Long.toString(Long.parseLong(p) + i);
            String rev = new StringBuilder(pStr).reverse().toString();
            if (s.length() % 2 == 0) {
                c = append(c, Long.parseLong(pStr + rev));
            } else {
                c = append(c, Long.parseLong(pStr + rev.substring(1)));
            }
            i++;
        }
        long res = -1;
        int idx = 0;
        while (idx < c.length) {
            long x = c[idx++];
            if (x != num && (res == -1 || Math.abs(x - num) < Math.abs(res - num) || 
                            (Math.abs(x - num) == Math.abs(res - num) && x < res))) {
                res = x;
            }
        }
        return Long.toString(res);
    }
    private long[] append(long[] arr, long value) {
        long[] newArr = new long[arr.length + 1];
        int j = 0;
        while (j < arr.length) {
            newArr[j] = arr[j];
            j++;
        }
        newArr[arr.length] = value;
        return newArr;
    }
}

```
```python []
class Solution:
    def nearestPalindromic(self, s: str) -> str:
        n = int(s)
        res = -1
        c = [10**(len(s) - 1) - 1, 10**len(s) + 1]
        p = s[:(len(s) + 1) // 2]
        i = -1
        while i <= 1:
            pal = str(int(p) + i)
            r = pal[:len(s) // 2][::-1]
            c.append(int(pal + r))
            i += 1
        i = 0
        while i < len(c):
            x = c[i]
            if x != n and (res == -1 or abs(x - n) < abs(res - n) or 
                            (abs(x - n) == abs(res - n) and x < res)):
                res = x
            i += 1
        return str(res)
```
![image.png](https://assets.leetcode.com/users/images/cba4608c-9654-422b-a2a7-55081c84d005_1724466699.111698.png)

---
- [ Efficient Solution for "Find the Closest Palindrome" | C++ | 0ms Beats 100.00% | O(n) | Java | Py3](https://leetcode.com/problems/find-the-closest-palindrome/solutions/5681845/c-0ms-beats-10000-on-java-py3-efficient-solution)
---
