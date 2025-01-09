
---

> ## Intuition 🧩

The problem requires counting the number of words in an array that start with a given prefix. This can be efficiently solved using string matching techniques. Specifically:
- We check if each word starts with the prefix using the **find** function or slicing.

---

> ## Approach 🎯

1. **Iterate through the array of words** For each word, check if it starts with the given prefix.
2. **Prefix Check** 
   - In C++: Use $$std::string::find$$ with $$== 0$$ to check if the prefix matches the start of the word.
   - In Python: Use the $$startswith()$$ method.
   - In Java: Use the $$startsWith()$$ method.
3. **Count Matches** Increment the count whenever a match is found.
---

> ## Complexity 📊

- **Time Complexity** $$O(n * m)$$  
  - **n** is the number of words in the array.
  - **m** is the average length of the words or the prefix.
  Each word is checked against the prefix, resulting in an overall complexity of $$O(n * m)$$.

- **Space Complexity** **O(1)** The solution uses constant additional space.

---

## Code 💻
```cpp []
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return count_if(words.begin(), words.end(), [&](const string& word) {
            return word.find(pref) == 0;
        });
    }
};
```

```python []
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(word.startswith(pref) for word in words)
```

```java []
class Solution {
    public int prefixCount(String[] words, String pref) {
        int count = 0;
        for (String word : words) {
            if (word.startsWith(pref)) {
                count++;
            }
        }
        return count;
    }
}
```

> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/b2ee8f62-95db-468a-ba6e-8297cc995e90_1736383329.4776938.png)
> - **Java**
> ![image.png](https://assets.leetcode.com/users/images/c08b9956-5431-473d-9331-d883e2cdff5e_1736383339.8617845.png)
> - **Python3**
> ![image.png](https://assets.leetcode.com/users/images/ad70952c-83b7-4d5e-ac70-40f459925046_1736383350.2742326.png)
[💡 | O(n * m) | (C++, Java, Py3) -- 0ms Beats 100.00% | String Matching](https://leetcode.com/problems/counting-words-with-a-given-prefix/solutions/6251769/on-m-c-java-py3-0ms-beats-10000-string-m-uebq)

---

---