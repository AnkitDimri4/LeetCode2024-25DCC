
#
---

# **Intuition**
We can efficiently solve this problem using a **Trie** (prefix tree). A **Trie** helps in storing prefixes and counting their occurrences while reducing redundant comparisons. Each node in the Trie represents a character, and we increment the count for each character as we insert the strings. Once the Trie is built, we can quickly compute the prefix scores by traversing the Trie for each word.


# **Approach**
To solve the problem, we first construct a Trie by inserting each string character by character, incrementing the count for each node to track how many strings share that prefix. After building the Trie, we compute the prefix scores for each string by traversing the Trie and summing the counts of the nodes corresponding to each prefix, allowing us to efficiently determine the total score for every non-empty prefix of each string.

# **Complexity**
- **Time Complexity** $$O(n \cdot m)$$, where $$n$$ is the number of words, and $$m$$ is the average length of the words. We traverse each word multiple times: once for building the Trie and once for calculating the prefix scores.

- **Space Complexity** $$O(n \cdot m)$$ for storing the Trie.

---

# **Code**
```cpp []
struct T {
    T* c[26] = {};
    int cnt = 0;
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        T* r = new T();  
        for (auto& s : w) 
            for (T* n = r; auto ch : s) 
                n = n->c[ch - 'a'] ? n->c[ch - 'a'] : n->c[ch - 'a'] = new T(), n->cnt++;
        vector<int> res;
        for (auto& s : w) {
            int sc = 0;
            for (T* n = r; auto ch : s) 
                sc += (n = n->c[ch - 'a'])->cnt;
            res.push_back(sc);
        }
        return res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int count = 0;
    } 
    public int[] sumPrefixScores(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode node = root;
            for (char ch : word.toCharArray()) {
                if (node.children[ch - 'a'] == null) {
                    node.children[ch - 'a'] = new TrieNode();
                }
                node = node.children[ch - 'a'];
                node.count++;
            }
        }
        int[] result = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            TrieNode node = root;
            int score = 0;
            for (char ch : words[i].toCharArray()) {
                node = node.children[ch - 'a'];
                score += node.count;
            }
            result[i] = score;
        }
        return result;
    }
}
```
```python3 []
class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0
class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = TrieNode()
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
                node.count += 1
        result = []
        for word in words:
            node = root
            score = 0
            for ch in word:
                node = node.children[ch]
                score += node.count
            result.append(score)
        return result
```
---
- ![image.png](https://assets.leetcode.com/users/images/33599343-e7e4-47b0-8436-23a4d4888621_1727233098.2279394.png)
- [💡 O(n⋅m) | Easy Solution | C++ 462ms Beats 87.78% | Java Py3](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/)

---

Questions and feedback are welcome!
