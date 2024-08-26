##
---
# Intuition
In postorder traversal of an N-ary tree, we need to visit all the children of a node before visiting the node itself. This requires us to process each node's children first, and then the node itself. The problem can be solved both recursively and iteratively.

# Approach
1. **Recursive Approach** Traverse each node's children recursively, collect their values, and finally add the current node's value.
2. **Iterative Approach** Use a stack to simulate the recursive traversal. Push the root node and its children onto the stack, process nodes by reversing the order of their children to achieve postorder traversal.

# Complexity
- **Time complexity** $$O(n)$$ where $$n$$ is the number of nodes in the tree, as each node is processed once.
- **Space complexity** $$O(n)$$ due to the space required to store nodes in the stack or recursion stack.

# Code
```cpp []
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
private:
    void traverse(Node* n, vector<int>& res) {
        if (!n) return;
        for (auto& c : n->children) traverse(c, res);
        res.push_back(n->val);
    }
};
```
```java []
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        traverse(root, res);
        return res;
    }
    private void traverse(Node n, List<Integer> res) {
        if (n == null) return;
        for (Node c : n.children) traverse(c, res);
        res.add(n.val);
    }
}
```
```python []
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
class Solution:
    def postorder(self, root: Node) -> list[int]:
        res = []
        self.traverse(root, res)
        return res
    def traverse(self, node: Node, res: list[int]):
        if node is None:
            return
        for child in node.children:
            self.traverse(child, res)
        res.append(node.val)
```
![Screenshot 2024-08-26 061628.png](https://assets.leetcode.com/users/images/35701a6f-e9ac-423f-b501-535c810e37d5_1724634398.460819.png)

![image.png](https://assets.leetcode.com/users/images/c4daf289-9a2a-4c78-932a-b8ab0cc1943e_1724634360.6054492.png)

---
- [🌟C++ 3ms Beats 99.94% | Java 0ms Beats 100.00% | Python ✅| Recursive Postorder Traversal |](https://leetcode.com/problems/n-ary-tree-postorder-traversal/solutions/5691280/c-3ms-beats-99-94-java-0ms-beats-100-00-python-recursive-postorder-traversal)
---