#
---
# Intuition
The task is to insert a new node between every pair of adjacent nodes, containing the greatest common divisor (GCD) of their values. The GCD of two numbers is the largest number that divides both evenly, and this new node needs to be inserted after each node until the list is fully traversed.

# Approach
We iterate over the linked list, and for every adjacent pair of nodes, we compute the GCD of their values. We then insert a new node between them with this GCD value. This continues until the end of the list. The traversal requires advancing two nodes at a time since a new node is inserted in between the original nodes. This solution efficiently works in a single pass over the list.

# Complexity
- **Time complexity** $$𝑂(𝑛)$$, where n is the number of nodes in the linked list. We traverse each node once and perform constant time operations per node.
- **Space complexity** $$𝑂(1)$$, as we are only creating new nodes and not using any additional data structures proportional to the input size.


# Code
```cpp []
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto* cur = head; cur && cur->next; cur = cur->next->next) {
            cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
        }
        return head;
    }
};

```
```java []
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        for (ListNode cur = head; cur != null && cur.next != null; cur = cur.next.next) {
            cur.next = new ListNode(gcd(cur.val, cur.next.val), cur.next);
        }
        return head;
    }
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```

```python []
class Solution:
    def insertGreatestCommonDivisors(self, head: ListNode) -> ListNode:
        cur = head
        while cur and cur.next:
            gcd_val = math.gcd(cur.val, cur.next.val)
            new_node = ListNode(gcd_val)
            new_node.next = cur.next
            cur.next = new_node
            cur = cur.next.next
        return head
```

- ![image.png](https://assets.leetcode.com/users/images/4c64c358-64b3-4819-82ee-a872610ece14_1725937384.930238.png)
- [Efficient Solution | O(n) | C++ Java Py3 | 27ms Beats 97.17%](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10)

---