
🌟
---
---

# Intuition
The problem asks whether a linked list can be found as a downward path in a binary tree. We can approach this using **Depth-First Search (DFS)**. Start at any node in the tree and check if the values match with the linked list. If the current tree node matches the linked list's head, recursively check both left and right child nodes for subsequent list nodes. The key idea is to perform DFS on each tree node, looking for a potential match, and then follow each match downwards to make sure the entire list corresponds to a path in the tree.

# Approach
We start by checking each node in the binary tree to see if a path beginning from that node matches the linked list. If a match is found at the current node, we recursively check both the left and right children for the next node in the linked list. This process is repeated for all possible downward paths in the tree. The **isSubPath** function initiates this, while the **matches** function recursively verifies the path for matching nodes in both the tree and linked list.

# Time Complexity
- $$O(N * M)$$ Where N is the number of tree nodes and M is the length of the linked list. In the worst case, we check each tree node and traverse the entire linked list.

# Space Complexity
- $$O(H + M)$$ H is the height of the tree due to recursion, and M is the length of the linked list for recursive calls.

# Code
```cpp
class Solution {
public:
    bool isSubPath(ListNode* list, TreeNode* tree) {
        if (!tree) return false;
        return hasPath(tree, list);
    }
private:
    bool hasPath(TreeNode* node, ListNode* list) {
        if (!node) return false;
        return (matches(node, list) || hasPath(node->left, list) || hasPath(node->right, list));
    }
    bool matches(TreeNode* node, ListNode* list) {
        if (!list) return true; 
        if (!node || node->val != list->val) return false; 
        return matches(node->left, list->next) || matches(node->right, list->next);
    }
};
```

- 
![image.png](https://assets.leetcode.com/users/images/db9f2e88-e091-4fdf-a647-02ae0461bc80_1725691124.1216602.png)
- [ O(N * M) | Efficient DFS Approach | 11ms Beats 99.54% | C++ |](https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07)
---
