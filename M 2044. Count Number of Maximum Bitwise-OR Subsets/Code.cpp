#include <iostream>
#include <vector>
#include <numeric> // For accumulate

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a | b; });
        return dfs(nums, 0, 0, maxOr);
    }
private:
    int dfs(vector<int>& nums, int i, int orVal, int maxOr) {
        if (i == nums.size()) {
            return orVal == maxOr;
        }
        return dfs(nums, i + 1, orVal | nums[i], maxOr) + dfs(nums, i + 1, orVal, maxOr);
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Number of subsets with maximum OR: " << sol.countMaxOrSubsets(nums) << "\n";
    return 0;
}
