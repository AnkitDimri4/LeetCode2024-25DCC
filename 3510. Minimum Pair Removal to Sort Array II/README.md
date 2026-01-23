
---

# 3510. Minimum Pair Removal to Sort Array II

**Difficulty:** Hard
**Topics:** Array, Greedy, Heap (Priority Queue), Linked List Simulation
**Companies:** Premium
**Link:** [https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)

---

## **Intuition**

This problem is an extension of **Minimum Pair Removal to Sort Array I**, but with **much larger constraints** (`n ≤ 10⁵`).
A brute-force simulation (O(n²)) is no longer feasible.

We are repeatedly required to:

* Pick the **adjacent pair with the minimum sum**
* Prefer the **leftmost pair** in case of ties
* Replace the pair with their sum
* Count operations until the array becomes **non-decreasing**

The key challenge is to **efficiently maintain adjacency and minimum pair selection** while elements are dynamically removed.

---

## **Key Observations**

1. Only **adjacent pairs** matter → perfect for a **linked list simulation**
2. We always need the **minimum pair sum** → use a **min-heap**
3. The array becomes sorted when there are **no decreasing adjacent pairs**
4. Instead of rechecking the whole array every time, we can track how many
   **“bad pairs”** (`nums[i] > nums[i+1]`) exist

---

## **Optimized Strategy**

To handle large input efficiently:

### 🔹 Data Structures Used

| Structure        | Purpose                                   |
| ---------------- | ----------------------------------------- |
| `min-heap`       | Always extract the minimum adjacent pair  |
| `prv[]`, `nxt[]` | Simulate a doubly linked list             |
| `bitset rmv`     | Track removed indices                     |
| `bad counter`    | Track number of decreasing adjacent pairs |

---

## **Approach**

### 1️ Initial Checks

* If the array is already non-decreasing → return `0`
* Initialize:

  * Linked list (`prv`, `nxt`)
  * Min-heap of adjacent pair sums
  * Count of **bad adjacent pairs**

---

### 2️ Heap-Driven Simulation

While the array is **not sorted**:

1. Extract the **minimum sum adjacent pair**
2. Validate the pair (not removed, still adjacent, sum matches)
3. Update:

   * `bad` count (before and after merge)
   * Linked list pointers
   * Heap with newly formed adjacent pairs
4. Increment operation count

---

### 3️ Termination

* When `bad == 0`, the array is non-decreasing
* Return the number of operations performed

---

## 🔹 **Correctness Proof (Sketch)**

* The problem **forces** selecting the minimum sum adjacent pair each time
* Using a min-heap ensures the correct greedy choice
* Linked list simulation preserves adjacency after removals
* Tracking only affected neighbors guarantees correctness while maintaining efficiency

Thus, the algorithm exactly simulates the required operations in optimal time.

---

## 🔹 **Complexity Analysis**

* **Time Complexity:**
  `O(n log n)`
  Each pair is pushed and popped from the heap a constant number of times.

- <img width="503" height="424" alt="image" src="https://github.com/user-attachments/assets/861a35a6-26f5-4920-b12e-26935a48e4e6" />


* **Space Complexity:**
  `O(n)`
  For heap, linked list arrays, and removal tracking.

---

## 🔹 **C++ Implementation**

```cpp
using ll=long long;
using int2=pair<long long, int>;
const int N=1e5;
bitset<N> rmv=0;
int prv[N], nxt[N];
ll heap[3*N];
class Solution {
public:
    static inline ll pack(ll sum, unsigned idx){
        return ((ll)sum<<17)|idx;
    }
    static int minimumPairRemoval(vector<int>& nums_) {
        const int n=nums_.size();
        ll* nums=(ll*)alloca(n*sizeof(ll));
        copy(nums_.begin(), nums_.end(), nums);
        if (is_sorted(nums, nums+n)) return 0;
        rmv.reset();
        for (int i{0}; i<n; i++) {
            prv[i]=i-1;
            nxt[i]=(i+1<n)? i+1 : -1;
        }
        for (int i{0}; i<n-1; i++)
            heap[i]=pack(nums[i]+nums[i+1], i);
        int sz{n-1};
        make_heap(heap, heap+sz, greater<>());
        int bad{0};
        for (int i{0}; i<n-1; i++)
            if (nums[i]>nums[i+1]) bad++;
        int op{0};
        while (bad>0 && sz>0) {
            pop_heap(heap, heap+sz, greater<>());
            ll data=heap[--sz];
            ll sum=data>>17;
            int i=data&((1<<17)-1);
            if (rmv[i] || nxt[i]==-1) continue;
            int j=nxt[i];
            if (rmv[j] || nums[i]+nums[j] != sum) continue;
            int pi=prv[i];
            int nj=nxt[j];
            if (pi != -1 && nums[pi]>nums[i]) bad--;
            if (nums[i] > nums[j]) bad--;
            if (nj != -1 && nums[j]>nums[nj]) bad--;
            nums[i]=sum;
            rmv[j]=1;
            nxt[i]=nj;
            if (nj != -1) prv[nj]=i;
            if (pi!=-1 && nums[pi]>nums[i]) bad++;
            if (nj!=-1 && nums[i]>nums[nj]) bad++;
            if (pi != -1){
                heap[sz++]=pack(nums[pi]+nums[i], pi);
                push_heap(heap, heap+sz, greater<>());
            }
            if (nj != -1){
                heap[sz++]=pack(nums[i]+nums[nj], i);
                push_heap(heap, heap+sz, greater<>());
            }
            op++;
        }
        return op;
    }
};

```

- <img width="636" height="455" alt="image" src="https://github.com/user-attachments/assets/7a022a05-d2cc-4fd7-88ce-8ee22776810f" />

---

## **Key Takeaways**

* **Greedy + Heap** is essential when “minimum” operations are repeatedly required
* Linked list simulation avoids costly deletions
* Tracking only **local violations** (`bad pairs`) prevents repeated full scans
* This is a classic example of upgrading a brute-force idea into a scalable solution

---

<div align="center">
    Created by <b>Ankit Dimri</b>  
    © 2026
</div>

---

