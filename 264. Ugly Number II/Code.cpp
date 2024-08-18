#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> u(n, 1);
        for(auto i{1}, i2{0}, i3{0}, i5{0}; i < n; ++i) {
            u[i] = min({u[i2] * 2, u[i3] * 3, u[i5] * 5});
            i2 += (u[i] == u[i2] * 2);
            i3 += (u[i] == u[i3] * 3);
            i5 += (u[i] == u[i5] * 5);
        }
        return u.back();
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th ugly number is: " << sol.nthUglyNumber(n) << "\n";
    return 0;
}
