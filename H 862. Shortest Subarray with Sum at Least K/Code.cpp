#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1e5 + 1;
long long psum[MAX_SIZE];
int idx[MAX_SIZE];

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n + 1, s{0}, e{0};
        long long sum{0};
        psum[e] = 0, idx[e++] = -1; // Initialize prefix sum and index
        
        for (int i{0}; i < n; ++i) {
            sum += nums[i];
            // Check if the current subarray sum is at least k
            while (s < e && sum - psum[s] >= k)
                res = std::min(res, i - idx[s++]);
            // Maintain monotonic increasing order in the deque
            while (s < e && sum <= psum[e - 1])
                e--;
            psum[e] = sum, idx[e++] = i;
        }
        
        return res > n ? -1 : res;
    }
};

int main() {
    // Example 1
    vector<int> nums1 = {1};
    int k1 = 1;
    Solution solution;
    cout << "Output for nums1: " << solution.shortestSubarray(nums1, k1) << "\n"; // Output: 1

    // Example 2
    vector<int> nums2 = {1, 2};
    int k2 = 4;
    cout << "Output for nums2: " << solution.shortestSubarray(nums2, k2) << "\n"; // Output: -1

    // Example 3
    vector<int> nums3 = {2, -1, 2};
    int k3 = 3;
    cout << "Output for nums3: " << solution.shortestSubarray(nums3, k3) << "\n"; // Output: 3

    return 0;
}
