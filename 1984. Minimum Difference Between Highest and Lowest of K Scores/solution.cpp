#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int minimumDifference(vector<int>& nums, int k) {
        const int n=nums.size();
        if (k==1) return 0; 
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        for(int l{0}, r{k-1}; r<n; r++, l++){
            diff=min(diff, nums[r]-nums[l]);
        }
        return diff;
    }
};

// Optional main() for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {9, 4, 1, 7};
    int k1{2};
    cout << sol.minimumDifference(nums1, k1) << endl; // Expected: 2

    vector<int> nums2 = {90};
    int k2{1};
    cout << sol.minimumDifference(nums2, k2) << endl; // Expected: 0

    return 0;
}
