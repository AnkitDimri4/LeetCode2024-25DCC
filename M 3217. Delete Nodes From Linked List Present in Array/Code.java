import java.util.HashSet;
import java.util.Set;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> toRemove = new HashSet<>();
        for (int num : nums) toRemove.add(num);

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        while (current.next != null) {
            if (toRemove.contains(current.next.val)) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return dummy.next;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3};
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(5);

        Solution sol = new Solution();
        ListNode result1 = sol.modifiedList(nums1, head1);
        printList(result1);  // Output: 4 -> 5
    }

    private static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            head = head.next;
            if (head != null) System.out.print(" -> ");
        }
        System.out.println();
    }
}
