#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minGroups(vector<vector<int>>& iv) {
        vector<pair<int, int>> ev;
        for (auto& i : iv) ev.emplace_back(i[0], 1), ev.emplace_back(i[1] + 1, -1);
        sort(ev.begin(), ev.end());
        int grp{0}, cur{0};
        for (auto& e : ev) cur += e.second, grp = max(grp, cur);
        return grp;
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    cout << sol.minGroups(intervals) << "\n";
    return 0;
}
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
