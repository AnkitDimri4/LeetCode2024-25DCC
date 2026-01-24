#include <bits/stdc++.h>
using namespace std;
int freq[100001]={0};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        auto [m, M]=minmax_element(nums.begin(), nums.end());
        int l=*m, r=*M;
        memset( freq+l, 0, (r-l+1)*sizeof(int));
        for(int x: nums)
            freq[x]++;
        int maxP{0}, rN{0}, lN{0}, k=nums.size()/2;
        for(int pairN{1}; pairN<=k; pairN++) {
            while (lN<pairN) lN+=freq[l++];
            while (rN<pairN) rN+=freq[r--];
            maxP=max(maxP, l+r);
        }
        return maxP;
    }
};
// Fast I/O (as used in LeetCode submissions)
auto init = []() { ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 'c'; }();

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 5, 2, 3},
        {3, 5, 4, 2, 4, 6},
        {1, 1, 1, 1},
        {1, 100000, 2, 99999},
        {5, 4, 3, 2, 1, 6}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << "\nMinimized Max Pair Sum: "
             << sol.minPairSum(nums) << "\n\n";
    }

    return 0;
}
