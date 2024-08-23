#include <iostream>
#include <sstream>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;
class Solution {
public:
    string fractionAddition(string expr) {
        int num{0}, den{1}, n, d;
        char slash;
        for (istringstream in(expr); in >> n >> slash >> d; ) {
            num = num * d + n * den;
            den *= d;
            int gcd = std::gcd(abs(num), den);
            num /= gcd;
            den /= gcd;
        }
        return to_string(num) + "/" + to_string(den);
    }
};

int main() {
    Solution sol;
    cout << sol.fractionAddition("1/3-1/2") << endl;  // Output: "-1/6"
    cout << sol.fractionAddition("5/2+1/3") << endl;  // Output: "11/6"
    return 0;
}
