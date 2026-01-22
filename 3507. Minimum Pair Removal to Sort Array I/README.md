
---

# 585. Minimum Pair Removal to Sort Array I

**Difficulty:** Easy
**Topics:** Array, Greedy, Simulation
**Link:** [LeetCode Problem](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)

---

## **Intuition**

We are asked to find the **minimum number of operations** required to make an array **non-decreasing** by repeatedly performing the following operation:

* Select the **adjacent pair with the minimum sum**.
* If multiple such pairs exist, choose the **leftmost one**.
* Replace the pair with their **sum**, effectively removing one element.

A brute-force approach would simulate every operation until the array is sorted. However, we can optimize by:

1. Keeping track of removed elements using a **placeholder value** (e.g., `INT_MAX`) instead of physically removing elements from the array.
2. Always choosing the **minimum sum adjacent pair** that hasn’t been removed yet.

---

## **Approach**

### 1️ Check Non-Decreasing Array

Define a helper function `isNonDec`:

* Iterate through the array.
* Skip elements marked as removed (`INT_MAX`).
* If a current element is **less than the previous valid element**, return `false`.
* Otherwise, continue. If no violations, return `true`.

---

### 2️ Find Minimum Sum Pair

* Iterate through all **adjacent valid elements**.
* Track the pair with the **minimum sum**.
* Store the indices of this pair as `(s, t)`.

---

### 3️ Perform the Operation

* Replace `nums[s]` with the sum of `nums[s] + nums[t]`.
* Mark `nums[t]` as removed (`INT_MAX`).
* Increment the **operation counter**.

---

### 4️ Repeat Until Sorted

* Continue steps 1–3 until the array is non-decreasing.

---

## 🔹 **Complexity Analysis**

* **Time Complexity:**
  Each operation scans the array to find the minimum pair (`O(n)`) and checks if the array is sorted (`O(n)`).
  Worst-case total: `O(n²)`, where `n` is the size of the array (acceptable since `n ≤ 50`).

* **Space Complexity:** `O(1)` extra space, using in-place marking of removed elements.

---

## 🔹 **C++ Implementation**

```cpp
class Solution {
public:
    static bool isNonDec(int* nums, int n) {
        int prev=INT_MIN;
        for (int i{0}; i<n; i++) {
            while (i<n && nums[i]==INT_MAX) i++;
            if (i==n) break;
            if (nums[i]<prev) return 0;
            prev=nums[i];
        }
        return 1;
    }
    static int minimumPairRemoval(vector<int>& _nums) {
        const int n=_nums.size();
        int* nums=_nums.data();
        int op{0};
        while (!isNonDec(nums, n)) {
            int minPair=INT_MAX, s{-1}, t{-1};
            for (int i{0}; i<n-1; i++) {
                if (nums[i]==INT_MAX) continue;
                int j{i+1};
                while (j<n && nums[j]==INT_MAX) j++;
                if (j<n && nums[j]!=INT_MAX) {
                    int pairSum=nums[i]+nums[j];
                    if (pairSum<minPair) {
                        minPair=pairSum;
                        s=i;
                        t=j;
                    }
                }
            }
            if (s!=-1 && t!=-1) {
                nums[s]+=nums[t];
                nums[t]=INT_MAX;
                op++;
            } 
            else 
                break; 
        }
        return op;
    }
};


```

---

## **Key Takeaways**

* Simulation problems can often be optimized using **placeholder values** instead of physically removing elements.
* Carefully handling **skipped elements** ensures correctness in operations.
* Greedy approach works here because we always remove the **minimum sum pair**, which is the optimal local choice.

---


