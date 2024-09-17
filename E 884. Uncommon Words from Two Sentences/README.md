#
---

# Intuition
The task is to find uncommon words that appear exactly once between two sentences. We can combine the two sentences and use a hash map (or dictionary) to count the frequency of each word. Finally, we collect the words that appear exactly once.

# Approach  
We first split both sentences into words and store their occurrences in a map (or hash table). After counting the frequency of each word, we traverse the map to collect words that appear exactly once. This make sures we capture the uncommon words from both sentences. Finally, we return the result as a list of these uncommon words. 

# Complexity:
- **Time Complexity** $$O(n)$$, where $$n$$ is the total number of words in both sentences.
- **Space Complexity** $$O(n)$$, for storing the word counts and the result.

# Code
```cpp []
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        for (stringstream ss(s1 + " " + s2); ss >> s1;) m[s1]++;
        vector<string> r;
        for (auto& [k, v] : m) if (v == 1) r.push_back(k);
        return r;
    }
};
```

```java []
class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> m = new HashMap<>();
        for (String word : (s1 + " " + s2).split(" ")) {
            m.put(word, m.getOrDefault(word, 0) + 1);
        }
        List<String> r = new ArrayList<>();
        for (String k : m.keySet()) {
            if (m.get(k) == 1) r.add(k);
        }
        return r.toArray(new String[0]);
    }
}
```

```python []
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        from collections import Counter
        words = s1.split() + s2.split()
        count = Counter(words)
        return [word for word, freq in count.items() if freq == 1]
```

---
-  
![image.png](https://assets.leetcode.com/users/images/dfce5315-1a37-4aa5-b95e-fe0bbb33a8cc_1726543463.5358427.png)
- [Easy Solution | C++ 0ms Beats 100.00% Java Py3 | O(n)](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17)

---
