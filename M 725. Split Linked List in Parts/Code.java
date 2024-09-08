class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        for (ListNode p = head; p != null; p = p.next) n++;
        int size = n / k, extra = n % k;
        ListNode[] res = new ListNode[k];
        ListNode curr = head;
        for (int i = 0; i < k && curr != null; i++) {
            res[i] = curr;
            int currPartSize = size + (extra > 0 ? 1 : 0);
            extra--;
            for (int j = 1; j < currPartSize; j++) curr = curr.next;
            ListNode nextPart = curr.next;
            curr.next = null;
            curr = nextPart;
        }
        return res;
    }
}

// Helper function to print the linked list
public static void printList(ListNode head) {
    while (head != null) {
        System.out.print(head.val + " ");
        head = head.next;
    }
    System.out.println("NULL");
}


public static void main(String[] args) {
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);
    head.next.next.next.next = new ListNode(5);
    
    Solution solution = new Solution();
    ListNode[] result = solution.splitListToParts(head, 3);
    
    for (ListNode part : result) {
        printList(part);
    }
}
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        for (ListNode p = head; p != null; p = p.next) n++;
        int size = n / k, extra = n % k;
        ListNode[] res = new ListNode[k];
        ListNode curr = head;
        for (int i = 0; i < k && curr != null; i++) {
            res[i] = curr;
            int currPartSize = size + (extra > 0 ? 1 : 0);
            extra--;
            for (int j = 1; j < currPartSize; j++) curr = curr.next;
            ListNode nextPart = curr.next;
            curr.next = null;
            curr = nextPart;
        }
        return res;
    }
}

// Helper function to print the linked list
public static void printList(ListNode head) {
    while (head != null) {
        System.out.print(head.val + " ");
        head = head.next;
    }
    System.out.println("NULL");
}

public static void main(String[] args) {
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(4);
    head.next.next.next.next = new ListNode(5);
    
    Solution solution = new Solution();
    ListNode[] result = solution.splitListToParts(head, 3);
    
    for (ListNode part : result) {
        printList(part);
    }
}
