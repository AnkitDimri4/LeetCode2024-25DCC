#

---

# Intuition
The problem requires filling a matrix in a spiral order with values from a linked list. We can approach this problem by simulating the movement in the matrix, moving right, down, left, and up in a spiral manner while populating values from the linked list. If the linked list runs out of values, the remaining cells in the matrix are filled with **-1**.

# Approach
We initialize an empty matrix of size **m x n** with **-1** as default values. We keep track of boundaries for the top, bottom, left, and right. Starting from the top-left corner, we traverse the matrix in a spiral order, updating the matrix with the linked list values until the list is exhausted. At each direction change, we adjust the boundaries accordingly to make sure we stay within the valid range.

# Complexity
- **Time Complexity** $$O(m \times n)$$ since we traverse all the cells in the matrix.
- **Space Complexity** $$O(m \times n)$$ for storing the matrix.

# Code

```cpp []
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1)); 
        int t{0}, b = m - 1, l{0}, r = n - 1, d{0}; 
        ListNode* cur = head;
        for (; cur && t <= b && l <= r; d = (d + 1) % 4) {
            if (d == 0) { 
                for (int i = l; i <= r && cur; ++i, cur = cur->next) mat[t][i] = cur->val;
                ++t;
            } else if (d == 1) {  
                for (int i = t; i <= b && cur; ++i, cur = cur->next) mat[i][r] = cur->val;
                --r;
            } else if (d == 2) {  
                for (int i = r; i >= l && cur; --i, cur = cur->next) mat[b][i] = cur->val;
                --b;
            } else {  
                for (int i = b; i >= t && cur; --i, cur = cur->next) mat[i][l] = cur->val;
                ++l;
            }
        }
        return mat;
    }
};
```
```java []
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] mat = new int[m][n];
        for (int[] row : mat) {
            Arrays.fill(row, -1);
        }
        int t = 0, b = m - 1, l = 0, r = n - 1, d = 0;
        ListNode cur = head;
        while (cur != null && t <= b && l <= r) {
            if (d == 0) {
                for (int i = l; i <= r && cur != null; i++) {
                    mat[t][i] = cur.val;
                    cur = cur.next;
                }
                t++;
            } else if (d == 1) {
                for (int i = t; i <= b && cur != null; i++) {
                    mat[i][r] = cur.val;
                    cur = cur.next;
                }
                r--;
            } else if (d == 2) {
                for (int i = r; i >= l && cur != null; i--) {
                    mat[b][i] = cur.val;
                    cur = cur.next;
                }
                b--;
            } else {
                for (int i = b; i >= t && cur != null; i--) {
                    mat[i][l] = cur.val;
                    cur = cur.next;
                }
                l++;
            }
            d = (d + 1) % 4;
        }
        return mat;
    }
}
```
```python []
class Solution: 
    def spiralMatrix(self, m: int, n: int, head: ListNode) -> List[List[int]]:
        mat = [[-1] * n for _ in range(m)]
        t, b, l, r = 0, m - 1, 0, n - 1
        cur = head
        d = 0
        while cur and t <= b and l <= r:
            if d == 0: 
                for i in range(l, r + 1):
                    if cur:
                        mat[t][i] = cur.val
                        cur = cur.next
                t += 1
            elif d == 1:
                for i in range(t, b + 1):
                    if cur:
                        mat[i][r] = cur.val
                        cur = cur.next
                r -= 1
            elif d == 2:
                for i in range(r, l - 1, -1):
                    if cur:
                        mat[b][i] = cur.val
                        cur = cur.next
                b -= 1
            else:
                for i in range(b, t - 1, -1):
                    if cur:
                        mat[i][l] = cur.val
                        cur = cur.next
                l += 1
            d = (d + 1) % 4
        return mat
```

--- 
- ![image.png](https://assets.leetcode.com/users/images/18b4571d-b8d2-4f8b-b3ee-2ecad78fafac_1725866273.131618.png)
- [Efficient Solution | Spiral Matrix | C++ Java Py3 | O(m*n) | 135ms Beats 97.74%](https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09)
--- 

