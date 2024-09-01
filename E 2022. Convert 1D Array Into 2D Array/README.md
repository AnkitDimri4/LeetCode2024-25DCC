
#
---

# Intuition
When tasked with converting a 1D array into a 2D array, the first idea is to map the 1D array elements directly to the 2D array's row and column indices. If the total number of elements does not match the required number of elements in the 2D array, it's impossible to perform the conversion, and we should return an empty array.

# Approach
To solve the problem, first, validate if the size of the **original** array equals **m * n**; if not, return an empty array. Then, initialize a 2D vector **res** with **m** rows and **n** columns. Iterate through the **original** array and place each element in the correct position in the 2D array by calculating the row index as **i / n** and the column index as **i % n**. Finally, after placing all elements, return the constructed 2D array.

# Complexity
- **Time complexity** $$O(m \times n)$$ because we are iterating over each element in the original array exactly once.
- **Space complexity** $$O(m \times n)$$ for storing the result in a 2D array.

# Code
```cpp []
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        int i{0};
        while (i < original.size()) {
            res[i / n][i % n] = original[i];
            ++i;
        }
        return res;
    }
};
```

```java []
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (original.length != m * n) return new int[0][0];
        int[][] res = new int[m][n];
        int i = 0;
        while (i < original.length) {
            res[i / n][i % n] = original[i];
            i++;
        }
        return res;
    }
}
```

```python []
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        res = [[0] * n for _ in range(m)]
        i = 0
        while i < len(original):
            res[i // n][i % n] = original[i]
            i += 1
        return res
```

---
![image.png](https://assets.leetcode.com/users/images/079c97a0-bf8b-4972-b8f5-2ee4b8c86c36_1725160866.890066.png)

---
- [🌟| Beats 99.10% | C++ java Py3 | Efficient Conversion of 1D Array to 2D Array | 59ms |](https://leetcode.com/problems/convert-1d-array-into-2d-array/description/)
---
