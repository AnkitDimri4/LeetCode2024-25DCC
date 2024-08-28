#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool explore(vector<vector<int>>& g1, vector<vector<int>>& g2, int x, int y) {
        if (x < 0 || y < 0 || x >= g2.size() || y >= g2[0].size() || g2[x][y] == 0) return true;
        g2[x][y] = 0;
        bool valid = g1[x][y] == 1;
        valid &= explore(g1, g2, x + 1, y);
        valid &= explore(g1, g2, x - 1, y);
        valid &= explore(g1, g2, x, y + 1);
        valid &= explore(g1, g2, x, y - 1);
        return valid;
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int count{0};
        for (int i{0}; i < g2.size(); ++i) {
            for (int j{0}; j < g2[0].size(); ++j) {
                if (g2[i][j] == 1 && explore(g1, g2, i, j)) ++count;
            }
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    
    cout << sol.countSubIslands(grid1, grid2) << endl; // Output: 3

    return 0;
}
