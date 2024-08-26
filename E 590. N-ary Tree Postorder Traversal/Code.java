import java.util.ArrayList;
import java.util.List;
class Node {
    public int val;
    public List<Node> children;
    public Node() {}
    public Node(int _val) {
        val = _val;
    }
    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}
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
public class Main {
    public static void main(String[] args) {
        Node root = new Node(1, List.of(
            new Node(3, List.of(new Node(5), new Node(6))),
            new Node(2),
            new Node(4)
        ));
        
        Solution sol = new Solution();
        List<Integer> result = sol.postorder(root);
        
        System.out.println(result);
        // Output: [5, 6, 3, 2, 4, 1]
    }
}
