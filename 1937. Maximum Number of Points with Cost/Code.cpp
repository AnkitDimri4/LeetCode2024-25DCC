#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& pts) {
        int r{1}, n = pts[0].size();
        auto prev = vector<long long>(pts[0].begin(), pts[0].end()), curr = prev;
        while (r < pts.size()) {
            for (auto c{0}; c < n; ++c) curr[c] = prev[c];
            for (auto c{1}; c < n; ++c) curr[c] = max(curr[c], curr[c-1] - 1);
            for (auto c{n-2}; c >= 0; --c) curr[c] = max(curr[c], curr[c+1] - 1);
            for (auto c{0}; c < n; ++c) curr[c] += pts[r][c];
            prev = curr; ++r;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
int main() {
    Solution solution;
    
    vector<vector<int>> points1 = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    cout << "Maximum points for points1: " << solution.maxPoints(points1) << endl;

    vector<vector<int>> points2 = {{1, 5}, {2, 3}, {4, 2}};
    cout << "Maximum points for points2: " << solution.maxPoints(points2) << endl;

    return 0;
}
