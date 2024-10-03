#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = accumulate(nums.begin(), nums.end(), 0LL) % p, pre = 0, res = nums.size();
        if (!rem) return 0;
        unordered_map<int, int> mp = {{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            pre = (pre + nums[i]) % p;
            if (mp.count((pre - rem + p) % p)) 
                res = min(res, i - mp[(pre - rem + p) % p]);
            mp[pre] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    int result = sol.minSubarray(nums, p);
    cout << "Minimum subarray length to remove: " << result << "\n";
    return 0;
}
