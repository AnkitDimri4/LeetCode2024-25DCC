import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
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
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);

        Solution sol = new Solution();
        List<Integer> result = sol.postorderTraversal(root);

        System.out.println(result);
        // Output: [3, 2, 1]
    }
}
