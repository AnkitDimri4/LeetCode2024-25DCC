#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count{0};
        for (int x = start ^ goal; x; x >>= 1) count += x & 1;
        return count;
    }
};

int main() {
    Solution sol;
    int start = 10, goal = 7;
    cout << "Minimum bit flips: " << sol.minBitFlips(start, goal) << "\n";
    return 0;
}
