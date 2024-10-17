import java.util.Scanner;

class Solution {
    public int maximumSwap(int num) {
        char[] s = Integer.toString(num).toCharArray();
        int[] last = new int[10];
        for (int i = 0; i < s.length; i++) 
            last[s[i] - '0'] = i;
        for (int i = 0; i < s.length; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    char temp = s[i];
                    s[i] = s[last[d]];
                    s[last[d]] = temp;
                    return Integer.parseInt(new String(s));
                }
            }
        }
        return num;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int num = sc.nextInt();
        System.out.println("Input: " + num);
        int result = solution.maximumSwap(num);
        System.out.println("Output: " + result); // Output should be 7236 if input is 2736
        sc.close();
    }
}
