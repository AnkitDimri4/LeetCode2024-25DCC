

---

🌟

# Intuition & Approach
We need to remove all nodes from the linked list whose values are present in the given array **nums**. We can achieve this efficiently by using a **bitset** to track the values that need to be removed, ensuring constant time checks. We initialize a dummy node to simplify the list manipulation and iterate through the list, bypassing nodes that are in the **bitset**. This method is efficient and leverages the bitset for fast lookups.

# Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the number of nodes in the linked list, as we traverse the list once.
- **Space Complexity** $$O(m)$$, where $$m$$ is the number of elements in **nums**, due to the space required for the bitset.

---

```cpp []
#include <vector>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> filter;
        for (int num : nums) filter[num] = 1;
        ListNode dummy(0); dummy.next = head;
        for (ListNode* node = &dummy; node->next;)
            filter[node->next->val] ? node->next = node->next->next : node = node->next;
        return dummy.next;
    }
};
static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
```

```python []
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
```

```java []
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
```

- 
![image.png](https://assets.leetcode.com/users/images/fda2deb1-905e-40ce-9a95-8caa222ce490_1725593640.6640737.png)
- [🌟| Efficient Solution || 229ms Beats 99.99% | O(n) | C++ Py3 Java |](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/)
---
