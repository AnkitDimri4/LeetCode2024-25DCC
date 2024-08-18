#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minV = arrays[0][0], maxV = arrays[0].back(), maxDis{0},i{1};
        while (i < arrays.size()) {
            maxDis = max(maxDis, max(arrays[i].back() - minV, maxV - arrays[i][0]));
            minV = min(minV, arrays[i][0]);
            maxV = max(maxV, arrays[i].back());
            ++i;
        }
        return maxDis;
    }
};
int main() {
    Solution solution;

    vector<vector<int>> arrays1 = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << "Output: " << solution.maxDistance(arrays1) << endl; // Output: 4

    vector<vector<int>> arrays2 = {{1}, {1}};
    cout << "Output: " << solution.maxDistance(arrays2) << endl; // Output: 0
    return 0;
}
