#include <iostream>
#include <vector>
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
        postorder(root, res);
        return res;
    }
private:
    void postorder(TreeNode* n, vector<int>& res) {
        if (n) {
            postorder(n->left, res);
            postorder(n->right, res);
            res.push_back(n->val);
        }
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
