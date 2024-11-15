#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l{0}, r = n - 1;
        // Find the longest non-decreasing prefix
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0; // The array is already sorted
        // Find the longest non-decreasing suffix
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = min(n - l - 1, r); // The minimum subarray to remove
        for (int i = 0, j = r; i <= l && j < n; ) 
            arr[i] <= arr[j] ? res = min(res, j - i++ - 1) : ++j;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
    vector<int> arr2 = {5, 4, 3, 2, 1};
    vector<int> arr3 = {1, 2, 3};

    cout << "Test Case 1: " << sol.findLengthOfShortestSubarray(arr1) << "\n"; // Expected: 3
    cout << "Test Case 2: " << sol.findLengthOfShortestSubarray(arr2) << "\n"; // Expected: 4
    cout << "Test Case 3: " << sol.findLengthOfShortestSubarray(arr3) << "\n"; // Expected: 0

    return 0;
}
