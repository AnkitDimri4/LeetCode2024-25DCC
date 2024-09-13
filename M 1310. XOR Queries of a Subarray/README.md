#
---

# Intuition
The idea is to answer XOR range queries efficiently by using a prefix XOR array. The XOR from index i to j can be computed in constant time if we maintain a prefix XOR array, where each element represents the XOR of all elements up to that index.

# Approach
First, transform the input array into a prefix XOR array where each element stores the XOR of all previous elements, including itself. This allows us to answer range XOR queries by using the relationship:  If the query is from index L to R, the result is **prefix[R] ^ prefix[L-1]**. If L is 0, the result is simply prefix[R]. Thus, we loop through the queries and for each query, retrieve the XOR in constant time using the prefix array.

# Complexity
- **Time Complexity** $$𝑂(𝑛+𝑚)$$ where 𝑛 is the length of the input array and 𝑚 is the number of queries. We first construct the prefix XOR array in $$𝑂(𝑛)$$ time and then answer each query in constant time.
- **Space Complexity** $$𝑂(1)$$ extra space apart from the input arrays since we reuse the input array to store the prefix XOR values.

# Code
```cpp []
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        for (int i{1}; i < arr.size(); ++i) arr[i] ^= arr[i - 1];
        vector<int> res;
        for (auto& x : q) res.push_back(x[0] ? arr[x[1]] ^ arr[x[0] - 1] : arr[x[1]]);
        return res;
    }
};

```
```java []
class Solution {
    public int[] xorQueries(int[] arr, int[][] q) {
        for (int i = 1; i < arr.length; ++i) arr[i] ^= arr[i - 1];
        int[] res = new int[q.length];
        for (int i = 0; i < q.length; ++i) {
            res[i] = q[i][0] == 0 ? arr[q[i][1]] : arr[q[i][1]] ^ arr[q[i][0] - 1];
        }
        return res;
    }
}
```
```python []
class Solution:
    def xorQueries(self, arr: List[int], q: List[List[int]]) -> List[int]:
        for i in range(1, len(arr)):
            arr[i] ^= arr[i - 1]
        return [arr[right] ^ arr[left - 1] if left else arr[right] for left, right in q]
```

---
C++
- ![image.png](https://assets.leetcode.com/users/images/7ce9ca45-5cd2-4eb7-bd5d-3adb7c839582_1726196340.5590794.png)
Java 
- ![image.png](https://assets.leetcode.com/users/images/26896879-b585-4030-bdd3-4df10aae6921_1726196355.4499836.png)
- [|| 𝑂(𝑛+𝑚) | Easy Solution | C++41ms Beats 96.71% | Java 2ms Beats 100% | Py3](https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13)

---