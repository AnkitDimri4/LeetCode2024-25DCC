#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        int i{0};
        while (i < original.size()) {
            res[i / n][i % n] = original[i];
            ++i;
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;
    vector<vector<int>> result = sol.construct2DArray(original, m, n);
    for (auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
