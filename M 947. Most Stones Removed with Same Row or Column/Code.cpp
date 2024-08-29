#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int find(int x, unordered_map<int, int>& p) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }
    void unite(int x, int y, unordered_map<int, int>& p) {
        p[find(x, p)] = find(y, p);
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> p;
        for (auto& s : stones) {
            int r = s[0], c = ~(s[1]);
            if (!p.count(r)) p[r] = r;
            if (!p.count(c)) p[c] = c;
            unite(r, c, p);
        }
        unordered_set<int> roots;
        for (auto& s : stones) {
            roots.insert(find(s[0], p));
        }
        return stones.size() - roots.size();
    }
};
int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{2,2},{10000,2}};
    int result = sol.removeStones(stones);
    // Output: 1
    return result;
}
