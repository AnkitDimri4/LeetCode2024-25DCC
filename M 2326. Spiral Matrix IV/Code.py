class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def spiralMatrix(self, m: int, n: int, head: ListNode) -> List[List[int]]:
        mat = [[-1] * n for _ in range(m)]
        t, b, l, r = 0, m - 1, 0, n - 1
        cur = head
        d = 0
        while cur and t <= b and l <= r:
            if d == 0:
                for i in range(l, r + 1):
                    if cur:
                        mat[t][i] = cur.val
                        cur = cur.next
                t += 1
            elif d == 1:
                for i in range(t, b + 1):
                    if cur:
                        mat[i][r] = cur.val
                        cur = cur.next
                r -= 1
            elif d == 2:
                for i in range(r, l - 1, -1):
                    if cur:
                        mat[b][i] = cur.val
                        cur = cur.next
                b -= 1
            else:
                for i in range(b, t - 1, -1):
                    if cur:
                        mat[i][l] = cur.val
                        cur = cur.next
                l += 1
            d = (d + 1) % 4
        return mat

# Helper function to print the matrix
def print_matrix(mat):
    for row in mat:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    head = ListNode(3)
    head.next = ListNode(0)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(6)
    head.next.next.next.next = ListNode(8)
    head.next.next.next.next.next = ListNode(1)
    head.next.next.next.next.next.next = ListNode(7)
    head.next.next.next.next.next.next.next = ListNode(9)
    head.next.next.next.next.next.next.next.next = ListNode(4)
    head.next.next.next.next.next.next.next.next.next = ListNode(2)
    head.next.next.next.next.next.next.next.next.next.next = ListNode(5)
    head.next.next.next.next.next.next.next.next.next.next.next = ListNode(5)
    head.next.next.next.next.next.next.next.next.next.next.next.next = ListNode(0)

    sol = Solution()
    result =
