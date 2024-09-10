import math

class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next

class Solution:
    def insertGreatestCommonDivisors(self, head: ListNode) -> ListNode:
        cur = head
        while cur and cur.next:
            gcd_val = math.gcd(cur.val, cur.next.val)
            new_node = ListNode(gcd_val, cur.next)
            cur.next = new_node
            cur = cur.next.next
        return head

# Helper function to print the linked list
def print_list(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


if __name__ == "__main__":
    head = ListNode(18)
    head.next = ListNode(6)
    head.next.next = ListNode(10)
    head.next.next.next = ListNode(3)
    
    sol = Solution()
    modified_head = sol.insertGreatestCommonDivisors(head)
    print_list(modified_head)
