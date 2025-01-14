> ## Intuition 🧩
To find the prefix common array $$ C $$, we need to count the numbers that are common in both arrays $$ A $$ and $$ B $$ up to each index $$ i $$. By leveraging a **hash set (or a frequency array)**, we can efficiently track the numbers we have seen in both arrays and count their occurrences. This allows us to determine the prefix common count at each index without rechecking previous elements.

> ## Approach 🎯
1. Use a **hash set (or a frequency array)** to track the elements that have been encountered in $$ A $$ and $$ B $$.
2. Traverse both arrays simultaneously:
   - For each index $$ i $$, check if $$ A[i] $$ or $$ B[i] $$ has been seen before. If yes, it contributes to the prefix common count.
   - If not, add them to the hash set for future checks.
3. Update the prefix common count $$ C[i] $$ at each step.
4. Return the array $$ C $$, which contains the prefix common counts for all indices.


> ## Complexity 📊
- **Time Complexity** $$O(n)$$  Each element in $$ A $$ and $$ B $$ is processed once, and hash set or frequency array operations (insert and lookup) are $$ O(1) $$ on average.

- **Space Complexity** $$O(n)$$  The hash set can hold up to $$ n $$ unique elements in the worst case.
    - **Frequency Array Approach (Java)** Requires $$O(n)$$ space for the frequency array.

> ## Code 💻
```cpp []
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seen; 
        vector<int> C(n, 0);
        int commonCount{0};
        for (int i{0}; i < n; ++i) {
            if (seen.count(A[i])) ++commonCount;
            else seen.insert(A[i]);
            if (seen.count(B[i])) ++commonCount;
            else seen.insert(B[i]);
            C[i] = commonCount;
        }
        return C;
    }
};
```
```JavaScript []
var findThePrefixCommonArray = function(A, B) {
    let n = A.length;
    let seen = new Set();
    let C = Array(n).fill(0);
    let commonCount = 0;
    for (let i = 0; i < n; i++) {
        if (seen.has(A[i])) commonCount++;
        else seen.add(A[i]);
        if (seen.has(B[i])) commonCount++;
        else seen.add(B[i]);
        C[i] = commonCount;
    }
    return C;
};
```
```Java_FrequencyArrayApproach []
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] freq = new int[n + 1]; 
        int[] C = new int[n];
        int commonCount = 0;
        for (int i = 0; i < n; i++) {
            if (++freq[A[i]] == 2) commonCount++;
            if (++freq[B[i]] == 2) commonCount++;
            C[i] = commonCount;
        }
        return C;
    }
}
```
```Python3 []
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        seen = set()
        C = [0] * n
        commonCount = 0
        for i in range(n):
            if A[i] in seen: commonCount += 1
            else: seen.add(A[i])
            if B[i] in seen: commonCount += 1
            else: seen.add(B[i])
            C[i] = commonCount
        return C
```
> ### Note: 
> **This implementation uses a frequency array instead of a hash set, achieving the same complexity but with slightly better performance in this case due to reduced overhead.**
---
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/6a24686a-9eee-4b47-bf45-d784cd5ec93a_1736814032.0297782.png)
> - **JavaScript**
> ![image.png](https://assets.leetcode.com/users/images/f1194022-e846-4316-bd7e-2ed6e445cc82_1736815367.925504.png)
> - **Python3**
> ![image.png](https://assets.leetcode.com/users/images/891cdd95-3409-442c-8ff2-7ec32e515b32_1736815392.6413388.png)
> - **Java**
> ![image.png](https://assets.leetcode.com/users/images/90bfc312-96ca-4613-a207-32684a74ef0f_1736815443.3818722.png)

![💡 | O(n) | [C++, Py3 0ms] [Java 1ms JS 4ms] Beats 100.00% | Hash Set/Frequency Array](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions/6276260/on-c-py3-0ms-java-1ms-js-4ms-beats-10000-wd9r)
---


