class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        n, curr = 0, head
        while curr:
            n += 1
            curr = curr.next
        
        size, extra = divmod(n, k)
        res = []
        curr = head
        for _ in range(k):
            res.append(curr)
            for _ in range(size + (extra > 0) - 1 if curr else 0):
                curr = curr.next
            if curr:
                tmp = curr.next
                curr.next = None
                curr = tmp
            extra -= 1
        return res

# Helper function to print the linked list
def print_list(head):
    while head:
        print(head.val, end=' ')
        head = head.next
    print("NULL")

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    
    solution = Solution()
    result = solution.splitListToParts(head, 3)
    
    for part in result:
        print_list(part)
