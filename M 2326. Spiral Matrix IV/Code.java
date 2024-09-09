class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] mat = new int[m][n];
        for (int[] row : mat) {
            Arrays.fill(row, -1);
        }
        int t = 0, b = m - 1, l = 0, r = n - 1, d = 0;
        ListNode cur = head;
        while (cur != null && t <= b && l <= r) {
            if (d == 0) {
                for (int i = l; i <= r && cur != null; i++) {
                    mat[t][i] = cur.val;
                    cur = cur.next;
                }
                t++;
            } else if (d == 1) {
                for (int i = t; i <= b && cur != null; i++) {
                    mat[i][r] = cur.val;
                    cur = cur.next;
                }
                r--;
            } else if (d == 2) {
                for (int i = r; i >= l && cur != null; i--) {
                    mat[b][i] = cur.val;
                    cur = cur.next;
                }
                b--;
            } else {
                for (int i = b; i >= t && cur != null; i--) {
                    mat[i][l] = cur.val;
                    cur = cur.next;
                }
                l++;
            }
            d = (d + 1) % 4;
        }
        return mat;
    }
}

// Helper function to print the matrix
public class Main {
    public static void printMatrix(int[][] mat) {
        for (int[] row : mat) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(3);
        head.next = new ListNode(0);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(6);
        head.next.next.next.next = new ListNode(8);
        head.next.next.next.next.next = new ListNode(1);
        head.next.next.next.next.next.next = new ListNode(7);
        head.next.next.next.next.next.next.next = new ListNode(9);
        head.next.next.next.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next.next.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next.next.next.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next.next.next.next.next.next.next.next = new ListNode(0);

        Solution sol = new Solution();
        int[][] result = sol.spiralMatrix(3, 5, head);
        printMatrix(result);
    }
}
