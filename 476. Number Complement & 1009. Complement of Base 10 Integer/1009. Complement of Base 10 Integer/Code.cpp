#include <iostream>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;  
        int bitmask = 1, temp = n;
        while (temp > 0) {
            bitmask <<= 1;
            temp >>= 1;
        }
        bitmask -= 1;
        return bitmask ^ n;
    }
};
int main() {
    Solution sol;

    int num1 = 5;
    cout << "Input: " << num1 << "\n";
    cout << "Output: " << sol.bitwiseComplement(num1) << "\n"; // Output: 2

    int num2 = 7;
    cout << "Input: " << num2 << "\n";
    cout << "Output: " << sol.bitwiseComplement(num2) << "\n"; // Output: 0

    int num3 = 10;
    cout << "Input: " << num3 << "\n";
    cout << "Output: " << sol.bitwiseComplement(num3) << "\n"; // Output: 5

    return 0;
}
