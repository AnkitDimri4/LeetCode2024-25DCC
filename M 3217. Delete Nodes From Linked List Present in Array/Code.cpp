#include <iostream>
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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << " -> ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result1 = sol.modifiedList(nums1, head1);
    printList(result1);  // Output: 4 -> 5
    while (result1) {
        ListNode* temp = result1;
        result1 = result1->next;
        delete temp;
    }

    return 0;
}
