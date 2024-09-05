#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = mean * (n + rolls.size()), missSum = total - accumulate(rolls.begin(), rolls.end(), 0);
        if (missSum < n || missSum > 6 * n) return {};
        vector<int> res(n, missSum / n);
        int rem = missSum % n;
        for (int i = 0; i < rem; ++i) res[i]++;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4, n = 2;
    vector<int> result = sol.missingRolls(rolls, mean, n);

    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (int num : result) cout << num << " ";
        cout << endl;
    }

    return 0;
}
