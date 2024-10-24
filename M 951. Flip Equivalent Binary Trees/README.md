#

---

> # Intuition
The problem asks whether two binary trees can be made equivalent by flipping any number of nodes, swapping the left and right child subtrees. This can be solved using **Depth First Search (DFS)** by recursively comparing nodes in both trees. At each step, either the left and right subtrees must match directly, or we can check if flipping them makes them match.

> # Approach
The core idea is to traverse both trees simultaneously, comparing nodes. If both are **null**, they are trivially equivalent; if one is **null** and the other isn't, or their values differ, the trees are not equivalent. If the values match, we recursively check two cases: without flipping (compare left subtrees and right subtrees of both trees) and with flipping (compare the left subtree of one tree with the right subtree of the other, and vice versa). If either condition holds, the trees are flip equivalent.

> # Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the number of nodes in the trees. We visit each node once.
- **Space Complexity** $$O(h)$$, where $$h$$ is the height of the trees due to the recursive call stack.

---
> # Code
```cpp []
class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        return !r1 && !r2 || r1 && r2 && r1->val == r2->val &&
               ((flipEquiv(r1->left, r2->left) && flipEquiv(r1->right, r2->right)) ||
                (flipEquiv(r1->right, r2->left) && flipEquiv(r1->left, r2->right)));
    }
};
```
```python3 []
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True
        if not root1 or not root2 or root1.val != root2.val:
            return False
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or \
               (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))
```
```java []
class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null || root1.val != root2.val) return false;
        return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) ||
               (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
    }
}
```
---

> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/61693d91-5bb8-4fed-8175-c98eeb3963d5_1729758637.9297006.png)
> **Java**
> ![image.png](https://assets.leetcode.com/users/images/fa062ac9-0bd3-425b-bc36-369c6efa77ab_1729758663.9204538.png)
![image.png](https://assets.leetcode.com/users/images/910e9df5-4bd7-4368-b4ce-b4c531289eb3_1729758651.271653.png)
> **Python3**
> [💡 | O(n) | C++, Java, Python 0ms Beats 100% | DFS for Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24)
---
> ### Additional Note
> This DFS approach efficiently handles the comparison of both trees in all possible configurations, ensuring that flip equivalence is checked thoroughly.


---