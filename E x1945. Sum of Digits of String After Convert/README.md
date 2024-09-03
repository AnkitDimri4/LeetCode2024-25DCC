

🌟

# 
---

## Intuition
The problem involves converting a string into its numeric equivalent based on the position of each letter in the alphabet, then repeatedly summing the digits of the resulting number for a specified number of iterations. This approach efficiently handles the conversion and repeated transformations.

## Approach
First, convert the string into a numeric sequence by mapping each letter to its alphabetic position $$('a' -> 1, 'z' -> 26)$$. Then, sum the digits of this number for k iterations or until the sum is reduced to a single digit. The method is efficient given the problem constraints, as the length of the string is small, and the number of transformations is limited.

## Complexity
- **Time Complexity** $$O(n + m \times k)$$ where $$n$$ is the length of the string, and $$m$$ is the number of digits after conversion. The conversion step takes $$O(n)$$ time, and summing the digits takes $$O(m \times k)$$ in total.
- **Space Complexity** $$O(1)$$ since we use a few extra variables and a string for intermediate calculations, but the overall space used does not scale with the input size.

---

```cpp []
class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for (char c : s) num += to_string(c - 'a' + 1);
        while (k--) {
            int sum = 0;
            for (char d : num) sum += d - '0';
            num = to_string(sum);
        }
        return stoi(num);
    }
};
```

```java []
class Solution {
    public int getLucky(String s, int k) {
        StringBuilder num = new StringBuilder();
        for (char c : s.toCharArray()) {
            num.append(c - 'a' + 1);
        }
        while (k-- > 0) {
            int sum = 0;
            for (char digit : num.toString().toCharArray()) {
                sum += digit - '0';
            }
            num = new StringBuilder(String.valueOf(sum));
        }
        return Integer.parseInt(num.toString());
    }
}
```

```python []
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        num = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        for _ in range(k):
            num = str(sum(int(d) for d in num))
        return int(num)
```

![image.png](https://assets.leetcode.com/users/images/d33c6a86-8a2d-4eab-bc86-0596cee0fc51_1725334729.8530686.png)

- [| Efficient Solution | 0ms Beats 100% | C++ Java Python | O(n) | 🌟](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/)
---