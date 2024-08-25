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
