#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
private:
    void traverse(Node* n, vector<int>& res) {
        if (!n) return;
        for (auto& c : n->children) traverse(c, res);
        res.push_back(n->val);
    }
};
int main() {
    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    
    Solution sol;
    vector<int> result = sol.postorder(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    // Output: 5 6 3 2 4 1

    return 0;
}
