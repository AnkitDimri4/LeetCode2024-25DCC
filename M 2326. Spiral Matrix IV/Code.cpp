#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1)); 
        int t{0}, b = m - 1, l{0}, r = n - 1, d{0}; 
        ListNode* cur = head;
        for (; cur && t <= b && l <= r; d = (d + 1) % 4) {
            if (d == 0) { 
                for (int i = l; i <= r && cur; ++i, cur = cur->next) mat[t][i] = cur->val;
                ++t;
            } else if (d == 1) {  
                for (int i = t; i <= b && cur; ++i, cur = cur->next) mat[i][r] = cur->val;
                --r;
            } else if (d == 2) {  
                for (int i = r; i >= l && cur; --i, cur = cur->next) mat[b][i] = cur->val;
                --b;
            } else {  
                for (int i = b; i >= t && cur; --i, cur = cur->next) mat[i][l] = cur->val;
                ++l;
            }
        }
        return mat;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrix(3, 5, head);
    printMatrix(result);

    return 0;
}
