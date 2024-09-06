class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def modifiedList(self, nums, head):
        to_remove = set(nums)
        dummy = ListNode(0)
        dummy.next = head
        current = dummy
        while current.next:
            if current.next.val in to_remove:
                current.next = current.next.next
            else:
                current = current.next
        return dummy.next

def print_list(head):
    while head:
        print(head.val, end="")
        head = head.next
        if head:
            print(" -> ", end="")
    print()

nums1 = [1, 2, 3]
head1 = ListNode(1)
head1.next = ListNode(2)
head1.next.next = ListNode(3)
head1.next.next.next = ListNode(4)
head1.next.next.next.next = ListNode(5)

sol = Solution()
result1 = sol.modifiedList(nums1, head1)
print_list(result1)  # Output: 4 -> 5
