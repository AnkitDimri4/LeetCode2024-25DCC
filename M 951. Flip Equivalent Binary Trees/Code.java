class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null || root1.val != root2.val) return false;
        return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) ||
               (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
    }
}

// Input and output
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        root1.left.left = new TreeNode(4);
        root1.left.right = new TreeNode(5);
        root1.right.left = new TreeNode(6);
        root1.left.right.left = new TreeNode(7);
        root1.left.right.right = new TreeNode(8);

        TreeNode root2 = new TreeNode(1);
        root2.right = new TreeNode(2);
        root2.left = new TreeNode(3);
        root2.right.left = new TreeNode(6);
        root2.left.left = new TreeNode(4);
        root2.left.right = new TreeNode(5);
        root2.right.left.left = new TreeNode(8);
        root2.right.left.right = new TreeNode(7);

        System.out.println(solution.flipEquiv(root1, root2)); // Output: true
    }
}
