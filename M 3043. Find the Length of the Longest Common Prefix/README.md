#
---
# Intuition
To efficiently find the **longest common prefix** between pairs of numbers in two arrays, we can use a **Trie** (prefix tree) to store one array, and then for each number in the second array, search the Trie for the longest matching prefix. This make sures that we avoid redundant comparisons, leveraging the structure of the Trie for fast prefix lookup.

# **Approach**  
To solve the problem, we first insert all elements of **arr1** into a Trie by converting the numbers to strings and using their digits as Trie nodes. Then, for each element in **arr2**, we traverse the Trie to determine how many digits from the left match with any element stored in it. During this traversal, we track the maximum common prefix length found across all pairs of elements from **arr1** and **arr2**. Finally, we return the maximum length of the common prefix identified.

# Complexity
- **Time Complexity** Inserting and searching in a Trie is proportional to the number of digits in the numbers. Given that $$n = arr1.length$$ and $$m = arr2.length$$, with a maximum of $$d$$ digits per number, the time complexity is $$O(n \cdot d + m \cdot d)$$.
- **Space Complexity** The space used by the Trie is proportional to the total number of digits across all numbers in $$arr1$$, which is $$O(n \cdot d)$$.

---
# Code

```cpp []
struct T {
    T *c[10] = {};
    void ins(string s) {
        T *n = this;
        for (char ch : s) {
            if (!n->c[ch - '0']) n->c[ch - '0'] = new T();
            n = n->c[ch - '0'];
        }
    }
    int pref(string s) {
        T *n = this;
        int len{0};
        for (char ch : s) {
            if (!n->c[ch - '0']) break;
            n = n->c[ch - '0'];
            ++len;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& a1, vector<int>& a2) {
        T t;
        for (int x : a1) t.ins(to_string(x));
        int mx{0};
        for (int x : a2) mx = max(mx, t.pref(to_string(x)));
        return mx;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
```

```java []
class TrieNode {
    TrieNode[] children = new TrieNode[10];
    void insert(String s) {
        TrieNode node = this;
        for (char ch : s.toCharArray()) {
            if (node.children[ch - '0'] == null) {
                node.children[ch - '0'] = new TrieNode();
            }
            node = node.children[ch - '0'];
        }
    }
    int prefix(String s) {
        TrieNode node = this;
        int length = 0;
        for (char ch : s.toCharArray()) {
            if (node.children[ch - '0'] == null) break;
            node = node.children[ch - '0'];
            length++;
        }
        return length;
    }
}
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        TrieNode trie = new TrieNode();
        for (int num : arr1) {
            trie.insert(String.valueOf(num));
        }
        int maxLength = 0;
        for (int num : arr2) {
            maxLength = Math.max(maxLength, trie.prefix(String.valueOf(num)));
        }
        return maxLength;
    }
}
```
```python3 []
class TrieNode:
    def __init__(self):
        self.children = {}
    def insert(self, s: str):
        node = self
        for ch in s:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
    def prefix(self, s: str) -> int:
        node = self
        length = 0
        for ch in s:
            if ch not in node.children:
                break
            node = node.children[ch]
            length += 1
        return length
class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        trie = TrieNode()
        for num in arr1:
            trie.insert(str(num))
        max_len = 0
        for num in arr2:
            max_len = max(max_len, trie.prefix(str(num)))
        return max_len
```

---
- ![image.png](https://assets.leetcode.com/users/images/95a80bf4-787f-4c0c-a987-3f1a8da02e20_1727147913.3629515.png)
- ![💡 Efficient Trie-Based Solution | C++ 167ms Beats 99.07% | Java Py3](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24)

---