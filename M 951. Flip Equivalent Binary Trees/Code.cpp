#include <iostream>
#include <optional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        return !r1 && !r2 || r1 && r2 && r1->val == r2->val &&
               ((flipEquiv(r1->left, r2->left) && flipEquiv(r1->right, r2->right)) ||
                (flipEquiv(r1->right, r2->left) && flipEquiv(r1->left, r2->right)));
    }
};

int main() {
    Solution solution;

    // Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left = new TreeNode(3);
    root2->right->left = new TreeNode(6);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left->left = new TreeNode(8);
    root2->right->left->right = new TreeNode(7);

    cout << (solution.flipEquiv(root1, root2) ? "true" : "false") << "\n"; // Output: true

    return 0;
}
