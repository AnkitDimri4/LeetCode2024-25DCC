#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto* cur = head; cur && cur->next; cur = cur->next->next) {
            cur->next = new ListNode(__gcd(cur->val, cur->next->val), cur->next);
        }
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);
    
    Solution sol;
    ListNode* modifiedHead = sol.insertGreatestCommonDivisors(head);
    printList(modifiedHead);
    
    return 0;
}
