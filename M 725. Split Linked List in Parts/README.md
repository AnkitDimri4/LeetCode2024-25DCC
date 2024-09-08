🌟 

---

## Intuition
The problem requires splitting a linked list into $$k$$ parts with as equal size as possible. To approach this, we first calculate the total length of the linked list, then compute the base size of each part. The first few parts may need to be slightly larger if the list length isn't divisible by $$k$$. After that, we traverse the list, disconnecting it as we go, and return an array of the split parts.

## Approach
We start by calculating the total number of nodes in the linked list. The base size of each part will be $$n / k$$, and the remaining nodes ($$n % k$$) are distributed across the first few parts to make sure the sizes differ by at most one. Then we traverse the list, creating sublists for each part and adjusting the $$next$$ pointers to separate them.

## Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the number of nodes in the linked list. We traverse the list to count the nodes and split the list in a second pass.
- **Space Complexity** $$O(k)$$ for the resulting array of $$k$$ parts.

## Code

```cpp []
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n{0};
        for (auto* p = head; p; p = p->next) n++; 
        int size = n / k, extra = n % k; 
        vector<ListNode*> res(k);
        for (auto* p = head; p; extra--, k--) {
            res[res.size() - k] = p; 
            for (int i = 1; i < size + (extra > 0); i++) p = p->next;
            auto* tmp = p->next;
            p->next = nullptr; 
            p = tmp;
        }
        return res;
    }
};
```

```java []
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        for (ListNode p = head; p != null; p = p.next) n++; 
        int size = n / k, extra = n % k;
        ListNode[] res = new ListNode[k];
        for (ListNode p = head; p != null; extra--, k--) {
            res[res.length - k] = p; 
            for (int i = 1; i < size + (extra > 0 ? 1 : 0); i++) p = p.next; 
            ListNode tmp = p.next;
            p.next = null; 
            p = tmp; 
        }
        return res;
    }
}
```

```python []
class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        n, p = 0, head
        while p:
            n += 1
            p = p.next 
        size, extra = divmod(n, k)
        res = []
        p = head
        for _ in range(k):
            res.append(p)
            for _ in range(size + (extra > 0) - 1 if p else 0):
                p = p.next
            if p:
                tmp = p.next
                p.next = None 
                p = tmp
            extra -= 1
        return res
```

---
- ![image.png](https://assets.leetcode.com/users/images/425fb619-e77b-48fc-be55-aa264544611d_1725765737.3242157.png)
- [Efficient Split Linked List Solution | C++ Java Py3 | O(n) | 3ms Beats 89.05%](https://leetcode.com/problems/split-linked-list-in-parts/description/)
---