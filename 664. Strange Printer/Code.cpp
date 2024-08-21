#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
    vector<vector<int>> memo;

    auto dp(string &s, int i, int j) -> int {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        auto res = dp(s, i + 1, j) + 1, k{i + 1};
        while (k <= j) {
            if (s[k] == s[i]) res = min(res, dp(s, i, k - 1) + dp(s, k + 1, j));
            ++k;
        }
        return memo[i][j] = res;
    }
public:
    auto strangePrinter(string s) -> int {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return dp(s, 0, n - 1);
    }
};
int main() {
    Solution sol;
    // Test case 1
    string s1 = "aaabbb";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.strangePrinter(s1) << endl;  // Output: 2
    // Test case 2
    string s2 = "aba";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.strangePrinter(s2) << endl;  // Output: 2

    return 0;
}
