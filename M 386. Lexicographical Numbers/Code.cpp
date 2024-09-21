#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i{1}; i < 10; ++i) add(i, n, res);
        return res;
    }
    void add(int x, int n, vector<int>& res) {
        if (x > n) return;
        res.push_back(x);
        for (int i{0}; i < 10 && x * 10 + i <= n; ++i) add(x * 10 + i, n, res);
    }
};

int main() {
    Solution sol;
    int n = 13;
    vector<int> result = sol.lexicalOrder(n);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
