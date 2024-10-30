#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (auto& dir : folder) {
            if (result.empty() || dir.compare(0, result.back().size(), result.back()) != 0 || dir[result.back().size()] != '/') {
                result.push_back(move(dir));
            }
        }
        return result;
    }
};
#include <iostream>
int main() {
    Solution solution;
    vector<string> folder1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> result1 = solution.removeSubfolders(folder1);
    for (const auto& dir : result1) cout << dir << " ";
    cout << "\n";  // Output: ["/a", "/c/d", "/c/f"]
    vector<string> folder2 = {"/a", "/a/b/c", "/a/b/d"};
    vector<string> result2 = solution.removeSubfolders(folder2);
    for (const auto& dir : result2) cout << dir << " ";
    cout << "\n";  // Output: ["/a"]
    return 0;
}
