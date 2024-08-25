---
# **Postorder Traversal**
---
- ## **Iterative Postorder Traversal**
---
- ### Intuition
To traverse a binary tree in postorder iteratively, we need to process the left and right children before the root node. Using a stack helps in managing the traversal state, but making sure that we visit nodes in the correct order requires careful handling of previously visited nodes.

- ### Approach
Use a stack to perform the **iterative traversal**. The stack helps in tracking nodes yet to be processed, and a **prev** pointer is used to track the previously processed node to confirm we handle right children correctly. The traversal follows the postorder pattern: left subtree, right subtree, then the node itself.

- ### Complexity
- **Time complexity** $$O(n)$$, where $$n$$ is the number of nodes in the tree. Each node is processed once.
- **Space complexity** $$O(h)$$, where $$h$$ is the height of the tree, due to the space used by the stack.

- ### Code
```cpp []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        for (; !stk.empty() || root; ) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                if (root->right && root->right != prev) {
                    root = root->right;
                } else {
                    res.push_back(root->val);
                    prev = root;
                    stk.pop();
                    root = nullptr;
                }
            }
        }
        return res;
    }
};
```

```java []
import java.util.*;
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stk = new Stack<>();
        TreeNode prev = null;
        for (; !stk.isEmpty() || root != null; ) {
            if (root != null) {
                stk.push(root);
                root = root.left;
            } else {
                root = stk.peek();
                if (root.right != null && root.right != prev) {
                    root = root.right;
                } else {
                    res.add(root.val);
                    prev = root;
                    stk.pop();
                    root = null;
                }
            }
        }
        return res;
    }
}
```

```python []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stk = []
        prev = None
        while stk or root:
            if root:
                stk.append(root)
                root = root.left
            else:
                root = stk[-1]
                if root.right and root.right != prev:
                    root = root.right
                else:
                    res.append(root.val)
                    prev = root
                    stk.pop()
                    root = None

        return res
```
![image.png](https://assets.leetcode.com/users/images/3ef60cb6-a014-443d-9fbf-83f1bc986087_1724547970.541586.png)

---

_______

- ## **Recursive Postorder Traversal**
---

- ### Intuition
To perform a postorder traversal of a binary tree recursively, you need to visit the left subtree, then the right subtree, and finally process the root node. The recursive approach naturally fits this traversal pattern by making recursive calls to process the left and right subtrees before handling the current node.

- ### Approach
Use a helper function to recursively traverse the binary tree in postorder. This function will visit the left and right children of each node before adding the node's value to the result list. The main function initializes the result list and starts the recursion from the root.

- ### Complexity
- **Time complexity** $$O(n)$$ where $$n$$ is the number of nodes in the tree. Each node is visited once.
- **Space complexity** $$O(h)$$ where $$h$$ is the height of the tree. This is due to the space used by the call stack during recursion.

- ### Code
```cpp []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
private:
    void postorder(TreeNode* n, vector<int>& res) {
        if (n) {
            postorder(n->left, res);
            postorder(n->right, res);
            res.push_back(n->val);
        }
    }
};
```

```java []
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        postorder(root, res);
        return res;
    }
    private void postorder(TreeNode node, List<Integer> res) {
        if (node != null) {
            postorder(node.left, res);
            postorder(node.right, res);
            res.add(node.val);
        }
    }
}
```

```python []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        self.postorder(root, res)
        return res
    def postorder(self, node: TreeNode, res: List[int]) -> None:
        if node:
            self.postorder(node.left, res)
            self.postorder(node.right, res)
            res.append(node.val)
```
---
- [✅ Efficient Iterative & Recursive Postorder Traversal | C++ | 0ms Beats 100.00% | Java | Python 🌟](https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/5686261/efficient-iterative-recursive-postorder-traversal-c-0ms-beats-100-00-java-python)
---

---