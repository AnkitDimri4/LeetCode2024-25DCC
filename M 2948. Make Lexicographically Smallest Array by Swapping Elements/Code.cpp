#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        auto sorted = arr;
        sort(begin(sorted), end(sorted));

        // Group elements based on the limit condition
        auto groups = sorted | views::chunk_by([limit](int x, int y) { return y - x <= limit; });

        vector<vector<int>::iterator> group_iters;
        vector<int> group_heads;

        // Track group heads and iterators for each group
        for (auto group : groups) {
            group_iters.push_back(group.begin());
            group_heads.push_back(group.front());
        }

        // Replace elements in the original array with the smallest available value from their group
        for (auto& x : arr) {
            auto it = prev(upper_bound(group_heads.begin(), group_heads.end(), x));
            auto& g_it = group_iters[distance(group_heads.begin(), it)];
            x = *g_it++;
        }

        return arr;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 5, 3, 9, 8};
    int limit1 = 2;
    vector<int> result1 = solution.lexicographicallySmallestArray(nums1, limit1);
    cout << "Output 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << "\n";

    // Example 2
    vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    int limit2 = 3;
    vector<int> result2 = solution.lexicographicallySmallestArray(nums2, limit2);
    cout << "Output 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << "\n";

    // Example 3
    vector<int> nums3 = {1, 7, 28, 19, 10};
    int limit3 = 3;
    vector<int> result3 = solution.lexicographicallySmallestArray(nums3, limit3);
    cout << "Output 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
