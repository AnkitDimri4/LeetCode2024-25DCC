import java.util.regex.*;

class Solution {
    public String fractionAddition(String expr) {
        int num = 0, den = 1;
        for (String s : expr.split("(?=[+-])")) {
            int[] frac = parseFraction(s);
            int gcd = gcd(Math.abs(num * frac[1] + frac[0] * den), den * frac[1]);
            num = (num * frac[1] + frac[0] * den) / gcd;
            den = (den * frac[1]) / gcd;
        }
        return num + "/" + den;
    }

    private int[] parseFraction(String s) {
        String[] parts = s.split("/");
        return new int[] { Integer.parseInt(parts[0]), Integer.parseInt(parts[1]) };
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.fractionAddition("1/3-1/2"));  // Output: "-1/6"
        System.out.println(sol.fractionAddition("5/2+1/3"));  // Output: "11/6"
    }
}
