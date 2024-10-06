#  

---
> # Intuition
To determine if two sentences can be made similar by inserting or removing words, we need to compare the matching prefix and suffix of both sentences. If the combined length of the matching prefix and suffix equals the length of one of the sentences, they are considered similar.

> # Approach
First, split both sentences into lists of words. Use two pointers: one for the beginning of each sentence to find the longest matching prefix, and another for the end to identify the matching suffix. If the total length of the matched prefix and suffix equals the length of either sentence, it confirms that the remaining words can be inserted between the matching parts, making the sentences similar.

> # Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the total number of words in the longer sentence. We traverse both sentences from the start and end in a single pass.
- **Space Complexity** $$O(n)$$ for storing the split words in two lists.

---

# Code
```cpp []
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1 = split(s1), w2 = split(s2);
        int i{0}, j{0}, n1 = w1.size(), n2 = w2.size();
        while (i < n1 && i < n2 && w1[i] == w2[i]) ++i;
        while (j < n1 - i && j < n2 - i && w1[n1 - 1 - j] == w2[n2 - 1 - j]) ++j;
        return i + j == n1 || i + j == n2;
    }
private:
    vector<string> split(const string& s) {
        istringstream ss(s);
        return {istream_iterator<string>(ss), istream_iterator<string>()};
    }
};
```
```Java []
class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        List<String> w1 = Arrays.asList(s1.split(" "));
        List<String> w2 = Arrays.asList(s2.split(" "));
        int i = 0, j = 0, n1 = w1.size(), n2 = w2.size();
        while (i < n1 && i < n2 && w1.get(i).equals(w2.get(i))) ++i;
        while (j < n1 - i && j < n2 - i && w1.get(n1 - 1 - j).equals(w2.get(n2 - 1 - j))) ++j;
        return i + j == n1 || i + j == n2;
    }
}
```
```python3 []
class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        w1, w2 = s1.split(), s2.split()
        i, j, n1, n2 = 0, 0, len(w1), len(w2)
        while i < n1 and i < n2 and w1[i] == w2[i]:
            i += 1
        while j < n1 - i and j < n2 - i and w1[n1 - 1 - j] == w2[n2 - 1 - j]:
            j += 1
        return i + j == n1 or i + j == n2
```

---

> **CPP** 
> ![image.png](https://assets.leetcode.com/users/images/5de7e3f0-f707-400d-809a-0b7634e179ba_1728184836.7080977.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/b0c63a07-154f-4405-b1d6-6adc3495ea66_1728184849.6420712.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/9152a7f9-e2fe-4df0-ad30-171c281fe1cf_1728184858.1196666.png)
[💡 | O(n) | C++ 0ms Beats 100.00% | Java 1ms | Python 18ms Beats 99.38% | Sentence Similarity III](https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06)

---

> ## Additional Note
> The two-pointer approach $$achieves$$ an $$O(n)$$ time complexity by comparing words from both ends of the sentences in a single pass, minimizing unnecessary comparisons and improving efficiency. The space complexity is also $$O(n)$$ due to the storage of the words from both sentences. This method provides an optimal solution across all implementations.

---