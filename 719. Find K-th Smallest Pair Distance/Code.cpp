#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = nums[n-1] - nums[0];
        while (low < high) {
            int mid = (low + high) >> 1, count = 0, j = 0;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) ++j;
                count += j - i - 1;
            }
            if (count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3, 1};
    int k1 = 1;
    cout << "Output: " << solution.smallestDistancePair(nums1, k1) << endl;

    vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    cout << "Output: " << solution.smallestDistancePair(nums2, k2) << endl; 

    vector<int> nums3 = {1, 6, 1};
    int k3 = 3;
    cout << "Output: " << solution.smallestDistancePair(nums3, k3) << endl; 

    return 0;
}
