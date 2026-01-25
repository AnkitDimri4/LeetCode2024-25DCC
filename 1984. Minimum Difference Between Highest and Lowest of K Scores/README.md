
---

# 1984. Minimum Difference Between Highest and Lowest of K Scores

**Difficulty:** Easy  
**Topics:** Array, Sorting, Sliding Window  
**Companies:** Premium  
**Link:** https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

---

##  Intuition

We are given scores of students and must select **exactly `k` students** such that the **difference between the highest and lowest scores** is minimized.

To minimize this difference:
- The selected `k` elements should be **as close as possible**
- This naturally suggests **sorting the array**

After sorting, the best group of `k` students will always be found among **contiguous elements**.

---

## Key Insight

Once the array is sorted:
- Any valid group of `k` students corresponds to a window of size `k`
- The difference for a window `[l … r]` is `nums[r] - nums[l]`
- Slide the window and track the minimum difference

This avoids checking all combinations and keeps the solution efficient.

---

## Approach

1. If `k == 1`, return `0` (single element → no difference)
2. Sort the array
3. Use a sliding window of size `k`
4. For each window:
   - Compute `nums[r] - nums[l]`
   - Update the minimum difference
5. Return the minimum value found

---

## ⏱️ Complexity Analysis

- **Time Complexity:**  
  `O(n log n)` due to sorting

- <img width="436" height="397" alt="image" src="https://github.com/user-attachments/assets/374d08c9-e93b-4b46-9eaf-ff8b4e7acae6" />


- **Space Complexity:**  
  `O(1)` extra space (sorting in-place)

---

##  Example

**Input:**  
`nums = [9, 4, 1, 7], k = 2`

**Sorted:**  
`[1, 4, 7, 9]`

**Windows of size 2:**
- `[1,4] → 3`
- `[4,7] → 3`
- `[7,9] → 2` 

**Output:**  
`2`

---

## C++ Implementation

```cpp
class Solution {
public:
    static int minimumDifference(vector<int>& nums, int k) {
        const int n=nums.size();
        if (k==1) return 0; 
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        for(int l{0}, r{k-1}; r<n; r++, l++){
            diff=min(diff, nums[r]-nums[l]);
        }
        return diff;
    }
};

```

- <img width="593" height="480" alt="image" src="https://github.com/user-attachments/assets/e5bfade7-169f-44db-a8a9-2746741e5513" />


## Complete Implementation

See `solution.cpp` for the full implementation.

---

<div align="center">
    Created by <b>Ankit Dimri</b>  
    © 2026
</div>


---


