#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (auto n : nums) s.push_back(to_string(n));
        sort(s.begin(), s.end(), [](string &a, string &b) { return a + b > b + a; });
        string res = accumulate(s.begin(), s.end(), string());
        return res[0] == '0' ? "0" : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {10, 2};
    vector<int> nums2 = {3, 30, 34, 5, 9};

    cout << "Output 1: " << sol.largestNumber(nums1) << "\n"; // Output: "210"
    cout << "Output 2: " << sol.largestNumber(nums2) << "\n"; // Output: "9534330"

    return 0;
}
