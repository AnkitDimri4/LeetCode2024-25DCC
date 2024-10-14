
#
---

> # Intuition
The key to maximizing the score is repeatedly picking the largest number in the array and adding it to the score. Then, replace the number with its ceiling value after dividing it by 3. This way, each operation reduces the largest element, but makes sure we always pick the current maximum. A max heap (priority queue) allows efficient access to the largest element, which is important for this strategy.

> # Approach
To maximize the score, we use a max heap (priority queue) to efficiently access the largest number. In each of the $$k$$ operations, we extract the maximum element, add it to the score, and replace it with $$ceil(max/3)$$ to reduce its value. This makes sure we always pick the largest available number at each step. We repeat this process exactly $$k$$ times, and the accumulated score after all operations gives the final result. Using a heap makes sure efficient access to the largest number throughout the process.

> # Complexity
- **Time Complexity** $$O(k \log n)$$ because we perform $$k$$ operations and each operation takes $$O(log n)$$ to extract and reinsert elements into the heap.
- **Space Complexity** $$O(n)$$ for storing the elements in the priority queue.

---
> # Code
```cpp []
class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long res{0};
        while (k--) {
            res += pq.top();
            pq.push((pq.top() + 2) / 3);
            pq.pop();
        }
        return res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int num : nums) pq.add(num);
        long res = 0;
        while (k-- > 0) {
            int max = pq.poll();
            res += max;
            pq.add((max + 2) / 3);
        }
        return res;
    }
}
```

---
> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/130038ed-70ec-447d-98a5-b5ff0e55f1c4_1728885837.0584073.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/8a28a2da-d6ed-4f7c-b15c-94304c9932d6_1728885828.3630967.png)
![💡 | O (k log n) | C++ 124ms Beats 99.25% | Java 113ms Beats 99.05% | Easy Solution🧠 | |](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14)

---