#
---
> # Intuition
We aim to determine whether the array can be divided into pairs such that the sum of each pair is divisible by $$k$$. The key observation is that for any two numbers $$x$$ and $$y$$ to sum up and be divisible by $$k$$, their remainders when divided by $$k$$ must complement each other (i.e., **x % k** and **y % k** must add up to $$k$$). We can count how many numbers give each remainder and verify if valid pairs can be formed.

> # Approach
To solve the problem, we can use a frequency array to count occurrences of each remainder when the elements of the input array are divided by $$k$$. By iterating through the array, we calculate the remainder for each element and increment its count in the frequency array. After populating the frequency array, we first check if the count of elements with a remainder of $$0$$ is even, as they can only be paired with themselves. Then, we verify that the counts of elements with remainders $$i$$ and $$k-i$$ are equal for all valid $$i$$. If both conditions are met, we can successfully pair all elements such that their sums are divisible by $$k$$.

> # Complexity
- **Time Complexity** The time complexity is **O(n)**, where $$n$$ is the number of elements in the array $$arr$$. The loop iterates through all elements of $$arr$$ once to populate the frequency array, and then iterates through half of the range $$[1, k // 2]$$ to check if frequencies match. Each operation (modulus, indexing) is constant time, so the overall complexity remains linear.
  - Constructing the frequency array **O(n)**
  - Checking the frequency pairs: **O(k / 2) = O(k)** (in worst case, but typically much smaller than $$n$$).
  
  So, the total time complexity is **O(n + k)**, which simplifies to **O(n)** as $$k$$ is much smaller in most cases.

- **Space Complexity** The space complexity is **O(k)** due to the frequency array $$freq$$ of size $$k$$. Other than this array, only constant space is used for temporary variables. Since $$k$$ is independent of the input size $$n$$, the space complexity remains **O(k)**.

---
> # Code
```cpp []
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> f(k);
        for (int x : arr) f[(x % k + k) % k]++;
        if (f[0] % 2) return false;
        for (int i{1}; i <= k / 2; ++i) if (f[i] != f[k - i]) return false;
        return true;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] freq = new int[k];
        for (int x : arr) {
            freq[(x % k + k) % k]++;
        }
        if (freq[0] % 2 != 0) return false;
        for (int i = 1; i <= k / 2; ++i) {
            if (freq[i] != freq[k - i]) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1,2,3,4,5,10,6,7,8,9};
        int k = 5;
        System.out.println(sol.canArrange(arr, k)); 
    }
}
```
```python3 []
class Solution:
    def canArrange(self, arr, k):
        freq = [0] * k
        for x in arr:
            freq[x % k] += 1
        if freq[0] % 2:
            return False
        return all(freq[i] == freq[k - i] for i in range(1, k // 2 + 1))
```
---
- ### C++
   >  ![image.png](https://assets.leetcode.com/users/images/aa70a02f-0a24-4acf-9a13-156c0eb0ee86_1727750724.778693.png)
- ### Java 
   >  ![image.png](https://assets.leetcode.com/users/images/29a4dfa0-8c66-4809-882f-1e20ca835e89_1727750492.720897.png)

> [O(n) | C++ 31ms Beats 99.74% | Java 4ms Beats 98.97% | Python3 | Easy Solution || Modulo Arithmetic](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01)

---

> ### Additional Note
> **Note**: While the theoretical time complexity is $$O(n)$$, practical performance will also depend on the implementation of array accesses and the use of modulo operations in different programming languages.
