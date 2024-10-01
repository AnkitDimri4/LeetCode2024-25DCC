#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> f(k);
        for (int x : arr) f[(x % k + k) % k]++;
        if (f[0] % 2) return false; // Check pairs with sum divisible by k
        for (int i{1}; i <= k / 2; ++i) 
            if (f[i] != f[k - i]) return false; // Check complementary pairs
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9}; 
    int k = 5;
    cout << (sol.canArrange(arr, k) ? "true" : "false") << "\n"; 
    return 0;
}
