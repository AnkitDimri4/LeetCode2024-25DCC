import java.util.Scanner;

class Solution {
    public int minAddToMakeValid(String s) {
        int o = 0, c = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                o++;
            } else if (o > 0) {
                o--;
            } else {
                c++;
            }
        }
        return o + c;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a parentheses string: ");
        String input = sc.next();
        int result = solution.minAddToMakeValid(input);
        System.out.println("Minimum add to make parentheses valid: " + result);
        sc.close();
    }
}
