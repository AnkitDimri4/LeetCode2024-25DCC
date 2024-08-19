#include <iostream>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        int s{0};
        for (auto i{2}; i <= n; ++i)
            for (; n % i == 0; s += i, n /= i);
        return s;
    }
};
int main() {
    Solution sol;
    int n = 3;  
    cout << "Input: n = " << n << "\n";
    cout << "Output: " << sol.minSteps(n) << "\n";
    return 0;
}
