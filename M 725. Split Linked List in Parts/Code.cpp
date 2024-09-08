#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n{0};
        for (ListNode* p = head; p; p = p->next) n++; // Count total nodes
        int size = n / k, extra = n % k;  // Calculate size of each part
        vector<ListNode*> res(k, nullptr);
        ListNode* curr = head;
        for (int i{0}; i < k && curr; ++i) {
            res[i] = curr; // Assign current node as the start of this part
            int currPartSize = size + (extra > 0 ? 1 : 0); // Extra node for first 'extra' parts
            extra--;
            for (int j = 1; j < currPartSize; ++j) {
                curr = curr->next;  // Traverse to the end of current part
            }
            ListNode* nextPart = curr->next; // Store the start of the next part
            curr->next = nullptr; // Break the link to split the part
            curr = nextPart; // Move to the next part
        }
        
        return res;
    }
};
// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution solution;
    vector<ListNode*> result = solution.splitListToParts(head, 3);
    
    for (ListNode* part : result) {
        printList(part);
    }
    
    return 0;
}
