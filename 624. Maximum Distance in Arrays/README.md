---
# Intuition
To find the maximum distance between two integers from different arrays, track the minimum and maximum values as you iterate through the arrays. By maintaining the current minimum and maximum values, you can efficiently calculate the maximum possible distance between elements from different arrays.

# Approach
Initialize the minimum and maximum values with the first array's bounds. As you process each subsequent array, update the maximum distance based on the difference between the current array's bounds and the previous minimum and maximum values. Adjust the minimum and maximum values accordingly after each comparison to confirm the distance calculation is correct.

# Complexity
- **Time Complexity** $$O(m)$$, where $$m$$ is the number of arrays. We make a single pass through the arrays.
- **Space Complexity** $$O(1)$$, as only a fixed amount of extra space is used for tracking the minimum and maximum values.

# Code
```cpp []
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minV = arrays[0][0], maxV = arrays[0].back(), maxDis{0}, i{1};
        while (i < arrays.size()) {
            maxDis = max(maxDis, max(arrays[i].back() - minV, maxV - arrays[i][0]));
            minV = min(minV, arrays[i][0]);
            maxV = max(maxV, arrays[i].back());
            ++i;
        }
        return maxDis;
    }
};
```

```java []
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int minV = arrays.get(0).get(0), maxV = arrays.get(0).get(arrays.get(0).size() - 1), maxDis = 0, i = 1;
        while (i < arrays.size()) {
            List<Integer> arr = arrays.get(i);
            maxDis = Math.max(maxDis, Math.max(arr.get(arr.size() - 1) - minV, maxV - arr.get(0)));
            minV = Math.min(minV, arr.get(0));
            maxV = Math.max(maxV, arr.get(arr.size() - 1));
            i++;
        }
        return maxDis;
    }
}
```

```python []
class Solution:
    def maxDistance(self, arrays):
        minV, maxV = arrays[0][0], arrays[0][-1]
        maxDis = 0
        i = 1
        while i < len(arrays):
            maxDis = max(maxDis, max(arrays[i][-1] - minV, maxV - arrays[i][0]))
            minV = min(minV, arrays[i][0])
            maxV = max(maxV, arrays[i][-1])
            i += 1
        return maxDis

```
![image.png](https://assets.leetcode.com/users/images/69524787-9d2d-4733-ad37-ab0d7408b96f_1723775796.0362225.png)

- **[Efficient Solution for "Maximum Distance in Arrays" | 198ms Beats 98.58% || C++ || Python | Java](https://leetcode.com/problems/maximum-distance-in-arrays/solutions/5642953/efficient-solution-for-maximum-distance-in-arrays-198ms-beats-98-58-c-python-java)**
---