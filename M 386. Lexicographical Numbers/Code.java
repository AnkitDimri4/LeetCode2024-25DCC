import java.util.*;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i < 10; ++i) add(i, n, res);
        return res;
    }
    private void add(int x, int n, List<Integer> res) {
        if (x > n) return;
        res.add(x);
        for (int i = 0; i < 10 && x * 10 + i <= n; ++i) add(x * 10 + i, n, res);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 13;
        List<Integer> result = sol.lexicalOrder(n);
        
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
