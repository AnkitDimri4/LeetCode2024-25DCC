#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long res{0};
        while (k--) {
            res += pq.top();
            pq.push((pq.top() + 2) / 3);
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 10, 10, 10, 10}; // Example input
    int k = 5; // Example k
    long long result = sol.maxKelements(nums, k);
    cout << "Output: " << result << "\n"; // Output the result
    return 0;
}
