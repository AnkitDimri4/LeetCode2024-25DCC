#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        if (a.empty()) return {};
        int n = a.size();
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; ++i) b[i] = {a[i], i};
        sort(b.begin(), b.end());
        for (int r = 1, i = 0; i < n; ++i) {
            a[b[i].second] = r;
            if (i < n - 1 && b[i].first != b[i + 1].first) ++r;
        }
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> result = sol.arrayRankTransform(arr);

    cout << "Input: [";
    for (int num : arr) cout << num << " ";
    cout << "]\nOutput: [";
    for (int rank : result) cout << rank << " ";
    cout << "]" << "\n";

    return 0;
}
