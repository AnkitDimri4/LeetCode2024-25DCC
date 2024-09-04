#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& cmds, vector<vector<int>>& obs) {
        unordered_set<long> obsSet;
        for (auto& o : obs) obsSet.insert(static_cast<long>(o[0]) * 100000 + o[1]);
        vector<int> dirs = {0, 1, 0, -1}; 
        int x{0}, y{0}, d{0}, maxDist{0};
        for (int cmd : cmds) {
            if (cmd == -1) d = (d + 1) % 4; 
            else if (cmd == -2) d = (d + 3) % 4; 
            else {
                while (cmd--) {
                    int nx = x + dirs[d], ny = y + dirs[d ^ 1];
                    if (!obsSet.count(static_cast<long>(nx) * 100000 + ny)) {
                        x = nx; y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else break;
                }
            }
        }
        return maxDist;
    }
};

int main() {
    Solution sol;
    vector<int> cmds = {4, -1, 3};
    vector<vector<int>> obs = {{2, 4}};
    cout << sol.robotSim(cmds, obs) << endl; // Output: 25
    return 0;
}
