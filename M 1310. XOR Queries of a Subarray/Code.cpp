#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        for (int i{1}; i < arr.size(); ++i) arr[i] ^= arr[i - 1];
        vector<int> res;
        for (auto& x : q) res.push_back(x[0] ? arr[x[1]] ^ arr[x[0] - 1] : arr[x[1]]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> result = sol.xorQueries(arr, queries);
    for (int x : result) cout << x << " ";  // Output: 2 7 14 8
    return 0;
}
