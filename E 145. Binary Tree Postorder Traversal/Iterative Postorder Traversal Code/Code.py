class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

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

if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    sol = Solution()
    result = sol.postorderTraversal(root)
    print(result)
    # Output: [3, 2, 1]
