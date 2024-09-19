import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String expr) {
        List<Integer> res = new ArrayList<>();
        if (expr.chars().allMatch(Character::isDigit)) {
            res.add(Integer.parseInt(expr));
            return res;
        }
        for (int i = 0; i < expr.length(); ++i) {
            if (expr.charAt(i) == '+' || expr.charAt(i) == '-' || expr.charAt(i) == '*') {
                List<Integer> left = diffWaysToCompute(expr.substring(0, i));
                List<Integer> right = diffWaysToCompute(expr.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        res.add(expr.charAt(i) == '+' ? l + r : expr.charAt(i) == '-' ? l - r : l * r);
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String expression = "2*3-4*5";
        List<Integer> results = sol.diffWaysToCompute(expression);
        System.out.print("Output: ");
        for (int res : results) {
            System.out.print(res + " ");
        }
    }
}
