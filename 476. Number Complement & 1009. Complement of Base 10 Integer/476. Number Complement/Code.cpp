#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int bitmask = pow(2, ceil((double)log2(num + 1))) - 1;
        return (~num) & bitmask;
    }
};
int main() {
    Solution sol;

    int num1 = 5;
    cout << "Input: " << num1 << "\n";
    cout << "Output: " << sol.findComplement(num1) << "\n"; // Output: 2

    int num2 = 7;
    cout << "Input: " << num2 << "\n";
    cout << "Output: " << sol.findComplement(num2) << "\n"; // Output: 0

    int num3 = 10;
    cout << "Input: " << num3 << "\n";
    cout << "Output: " << sol.findComplement(num3) << "\n"; // Output: 5

    return 0;
}
