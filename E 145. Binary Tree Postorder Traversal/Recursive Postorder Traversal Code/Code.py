class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

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
if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)

    sol = Solution()
    result = sol.postorderTraversal(root)
    print(result)
    # Output: [3, 2, 1]
