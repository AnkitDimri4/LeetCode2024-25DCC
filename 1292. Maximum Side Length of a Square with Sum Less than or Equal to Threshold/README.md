
---

## 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Difficulty:** Medium  
**Topics:** Prefix Sum, Sliding Window, Matrix  
**Link:** https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

---

##  **Intuition** 

We are asked to find the **largest square submatrix** whose **sum of elements does not exceed a given threshold**.

A brute-force approach (checking all possible squares) would be too slow because:
- Matrix size can be up to **300 × 300**
- Each square sum computation would be expensive

 **Key Idea:**  
Use a **2D Prefix Sum** to compute any square’s sum in **O(1)** time, and then apply a **sliding window on square sizes** to efficiently find the largest valid square.

---

##  **Approach** 

### 1️ Build Prefix Sum Matrix
Transform the matrix so that:
```
mat[i][j] = sum of elements from (0,0) to (i,j)
```

This allows us to compute the sum of any square submatrix in constant time using inclusion–exclusion.

---

### 2️ Constant-Time Square Sum Calculation
For a square with top-left `(r0, c0)` and bottom-right `(r1, c1)`:

\[
\text{sum} = mat[r1][c1]
- mat[r0-1][c1]
- mat[r1][c0-1]
+ mat[r0-1][c0-1]
\]

(Handle boundaries carefully.)

---

### 3️ Sliding Window on Square Size
- For each possible starting row and column:
  - Expand the square diagonally
  - Shrink it from the top-left if the sum exceeds `threshold`
- Track the **maximum valid side length**

This avoids unnecessary recomputation and keeps the solution efficient.

---

## 🔹 **Complexity Analysis** 

- **Prefix Sum Construction:** `O(m × n)`
- **Sliding Window Traversal:** `O(m × n)`
- **Total Time Complexity:** **`O(m × n)`**
- **Space Complexity:** **`O(1)` extra space (in-place prefix sum)**

---

## 🔹 **C++ Implementation** 

```cpp
class Solution {
public:
    static int Sum(int r0, int r1, int c0, int c1, vector<vector<int>>& mat){
      return mat[r1][c1]-(r0?mat[r0-1][c1]:0)-(c0?mat[r1][c0-1]:0)+((r0>0 && c0>0)?mat[r0-1][c0-1]:0);
    }
    static int SL_W(int i0, int j0, int row, int col,
                    vector<vector<int>>& mat, int k){
        const int MM=min(row-i0, col-j0);
        int Len{0};
        for (int l{0}, r{0}; r<MM; r++) {
            int r0{i0+l}, r1{i0+r}, c0{j0+l}, c1{j0+r};
            int S=Sum(r0, r1, c0, c1, mat);
            while (l<r && S>k) {
                l++;
                r0++; c0++;
                S=Sum(r0, r1, c0, c1, mat);
            }
            if (S<=k) Len=max(Len, r-l+1);
        }
        return Len;
    }
    static int maxSideLength(vector<vector<int>>& mat, int k) {
        const int row=mat.size(), col=mat[0].size();
        for (int j{1}; j<col; j++) mat[0][j]+=mat[0][j-1];
        for (int i{1}; i<row; i++){
            mat[i][0]+=mat[i-1][0];
            for(int j=1; j<col; j++)
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
        }
        int ans{0};
        for (int i{0}; i<row; i++) {
            if (row-i<=ans) break;
            ans=max(ans, SL_W(i, 0, row, col, mat, k));
        }
        for (int j{1}; j<col; j++) {
            if (col-j<=ans) break;
            ans=max(ans, SL_W(0, j, row, col, mat, k));
        }
        return ans;
    }
};

```

---

##  **Key Takeaways** 
- **2D Prefix Sum** reduces submatrix sum queries to `O(1)`
- **Sliding window on square size** avoids brute-force
- Efficient and elegant solution within constraints

---

> **C++**
- <img width="642" height="530" alt="image" src="https://github.com/user-attachments/assets/91227592-99f6-41d1-aad8-3dfffe923e6e" />


---
