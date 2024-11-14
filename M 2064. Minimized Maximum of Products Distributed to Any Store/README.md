
# **Binary Search on Maximum Product Distributed**
# 
---
# Intuition 🧩
The problem requires distributing products into stores while minimizing the maximum number of products assigned to any store. We can achieve this by using **binary search** on the maximum number of products per store and checking if it is feasible to distribute the products accordingly.

# Approach
To solve the problem, we first sort the quantities of products in descending order to prioritize distributing larger quantities first. Then, we use **binary search** to determine the smallest possible value of the maximum number of products per store ($$x$$) such that we can still distribute all products among the given number of stores $$n$$. For each candidate value of $$x$$ during the binary search, we calculate how many stores are required by dividing each product’s quantity by $$x$$ and summing the total number of stores needed. Based on whether the required number of stores is less than or equal to $$n$$, we adjust the binary search bounds accordingly to find the optimal value of $$x$$.

# Complexity 📊
- **Time Complexity** $$O(m \log(\text{max(quantities)}))$$, where $$m$$ is the number of product types, and $$max(quantities)$$ is the maximum value in the $$quantities$$ array. The binary search runs $$O(\log(\text{max(quantities)}))$$ times, and for each iteration, we loop through the product types, which takes $$O(m)$$ time.
- **Space Complexity** $$O(m)$$, where $$m$$ is the number of product types. This space is used to store the quantities of products in the array.
---

# Code 💻
```cpp []
class Solution {
public:
    int minimizedMaximum(int stores, vector<int>& qty) {
        int low{1}, high = *max_element(qty.begin(), qty.end());
        while (low < high) {
            int mid = (low + high) / 2, needed{0};
            for (int q : qty) needed += (q + mid - 1) / mid;
            if (needed <= stores) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int low = 1, high = Arrays.stream(quantities).max().getAsInt();
        while (low < high) {
            int mid = (low + high) / 2, needed = 0;
            for (int q : quantities) needed += (q + mid - 1) / mid;
            if (needed <= n) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}
```
```Python3 []
class Solution:
    def _binarySearchSolution(self, stores: int, products: List[int]) -> int:
        products.sort(reverse=True)
        left, right = 1, products[0]
        while left <= right:
            mid = (left + right) // 2
            extra = stores - len(products)
            for p in products:
                extra -= math.ceil(p / mid) - 1
                if extra < 0: break
            if extra < 0:
                left = mid + 1
            else:
                right = mid - 1
                res = mid
        return res
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        return max(quantities) if n == len(quantities) else self._binarySearchSolution(n, quantities)
```
---

> ### **Images**
> - **CPP** 
>  ![image.png](https://assets.leetcode.com/users/images/211d0256-78c2-4b90-bff7-502e90cf4c8f_1731542869.369211.png)
> - **Python3** 
>  ![image.png](https://assets.leetcode.com/users/images/284d75bf-dbec-4c54-b063-aa5527bbef83_1731545373.041634.png)
> - **Java** 
![image.png](https://assets.leetcode.com/users/images/818c1db6-1a36-40c7-9260-96fe8a879648_1731545415.4559708.png)
- [💡O(m*log(max(quantities)))| [Py3, C++] - 306ms,15ms ✅Beats100.00% |Java 28ms|Efficient Solution🧠|](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/solutions/6042508/omlogmaxquantities-py3-c-306ms15ms-beats10000-java-28msefficient-solution)

---
> ### **Conclusion** 📝
> This approach uses **binary search** to efficiently solve the problem of distributing products to stores while minimizing the maximum number of products given to any store. It is optimal for the given constraints, with a time complexity of **O(m * log(max(quantities)))**.

---

