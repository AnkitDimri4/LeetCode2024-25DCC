
---

# 1877. Minimize Maximum Pair Sum in Array

**Difficulty:** Medium  
**Topics:** Array, Greedy, Counting Sort  
**Companies:** Premium  
**Link:** https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

---

##  Intuition

We are given an array of **even length** and must pair up elements such that:

- Every element is used exactly once
- The **maximum pair sum** among all pairs is minimized

To minimize the maximum pair sum, the optimal strategy is:

> Pair the **smallest available number** with the **largest available number**

This balances large values with small ones and avoids creating a large pair sum unnecessarily.

---

##  Key Insight

Instead of sorting (which costs `O(n log n)`), we can leverage the constraints:

- `1 ≤ nums[i] ≤ 100000`

This allows us to use a **frequency array (counting sort idea)** to simulate two pointers:
- One pointer from the smallest value
- One pointer from the largest value

---

##  Approach

1. Count the frequency of each number.
2. Use two pointers:
   - `l` → smallest available number
   - `r` → largest available number
3. For each pair:
   - Move `l` and `r` until enough elements are available
   - Form a pair `(l, r)`
   - Update the maximum pair sum
4. Repeat for `n / 2` pairs.

---

##  Complexity Analysis

- **Time Complexity:**  
  `O(N + (R − L))`  
  where `L = min(nums)` and `R = max(nums)`.

  This is because:
  - `O(N)` to build the frequency array
  - `O(R − L)` for the two-pointer sweep over the active value range

  In practice, this is often close to **O(N)**.

- <img width="436" height="234" alt="image" src="https://github.com/user-attachments/assets/0c5c936e-f718-43eb-b12b-7467e9be697e" />


- **Space Complexity:**  
  `O(R)` for the frequency array

---

## C++ Implementation

```cpp
int freq[100001]={0};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        auto [m, M]=minmax_element(nums.begin(), nums.end());
        int l=*m, r=*M;
        memset( freq+l, 0, (r-l+1)*sizeof(int));
        for(int x: nums)
            freq[x]++;
        int maxP{0}, rN{0}, lN{0}, k=nums.size()/2;
        for(int pairN{1}; pairN<=k; pairN++) {
            while (lN<pairN) lN+=freq[l++];
            while (rN<pairN) rN+=freq[r--];
            maxP=max(maxP, l+r);
        }
        return maxP;
    }
};
auto init = []() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 'c'; }();

```

- <img width="606" height="475" alt="image" src="https://github.com/user-attachments/assets/fbe25f66-7c9d-4c67-95a0-d07d81bce13f" />

---

- This avoids explicit sorting and efficiently simulates the greedy pairing strategy using value frequencies.




---

<div align="center">
    Created by <b>Ankit Dimri</b>  
    © 2026
</div> 


--- 

