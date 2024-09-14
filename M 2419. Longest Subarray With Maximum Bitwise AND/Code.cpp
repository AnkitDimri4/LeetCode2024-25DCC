#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), res{0}, cnt{0};
        for (int n : nums) res = max(res, cnt = (n == mx ? cnt + 1 : 0));
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    cout << sol.longestSubarray(nums) << "\n"; // Output: 2
    return 0;
}
