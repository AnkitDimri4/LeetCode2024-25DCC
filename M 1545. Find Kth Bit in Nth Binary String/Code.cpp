#include <iostream>
using namespace std;
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0'; 
        int len = (1 << n) - 1, mid = len / 2 + 1;
        return (k < mid) ? findKthBit(n - 1, k) : (k == mid) ? '1' : invert(findKthBit(n - 1, len - k + 1));
    }
private:
    char invert(char c) {
        return c ^ 1; 
    }
};
int main() {
    Solution sol;
    int n = 3, k = 1;
    cout << "Input: n = " << n << ", k = " << k << "\nOutput: " << sol.findKthBit(n, k) << "\n"; // Output: 0
    n = 4; k = 11;
    cout << "Input: n = " << n << ", k = " << k << "\nOutput: " << sol.findKthBit(n, k) << "\n"; // Output: 1
    return 0;
}
