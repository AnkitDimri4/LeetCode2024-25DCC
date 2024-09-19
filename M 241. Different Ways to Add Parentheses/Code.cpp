#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expr) {
        vector<int> res;
        if (all_of(expr.begin(), expr.end(), ::isdigit)) return {stoi(expr)};
        for (int i = 0; i < expr.size(); ++i) {
            if (ispunct(expr[i])) {
                auto left = diffWaysToCompute(expr.substr(0, i));
                auto right = diffWaysToCompute(expr.substr(i + 1));
                for (int l : left) 
                    for (int r : right) 
                        res.push_back(expr[i] == '+' ? l + r : expr[i] == '-' ? l - r : l * r);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string expression = "2*3-4*5";
    vector<int> results = sol.diffWaysToCompute(expression);
    cout << "Output: ";
    for (int res : results) cout << res << " ";
    return 0;
}
