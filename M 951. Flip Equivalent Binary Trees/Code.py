class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True
        if not root1 or not root2 or root1.val != root2.val:
            return False
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or \
               (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))

# Input
root1 = TreeNode(1)
root1.left = TreeNode(2)
root1.right = TreeNode(3)
root1.left.left = TreeNode(4)
root1.left.right = TreeNode(5)
root1.right.left = TreeNode(6)
root1.left.right.left = TreeNode(7)
root1.left.right.right = TreeNode(8)

root2 = TreeNode(1)
root2.right = TreeNode(2)
root2.left = TreeNode(3)
root2.right.left = TreeNode(6)
root2.left.left = TreeNode(4)
root2.left.right = TreeNode(5)
root2.right.left.left = TreeNode(8)
root2.right.left.right = TreeNode(7)

solution = Solution()
print(solution.flipEquiv(root1, root2))  # Output: True
