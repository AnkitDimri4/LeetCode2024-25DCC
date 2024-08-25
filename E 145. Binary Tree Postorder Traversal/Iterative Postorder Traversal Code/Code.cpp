#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        for (; !stk.empty() || root; ) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                if (root->right && root->right != prev) {
                    root = root->right;
                } else {
                    res.push_back(root->val);
                    prev = root;
                    stk.pop();
                    root = nullptr;
                }
            }
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    // Output: 3 2 1

    return 0;
}
