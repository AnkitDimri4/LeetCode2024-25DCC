#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbal{0}, maxImbal{0};
        for (char c : s) 
            maxImbal = max(maxImbal, imbal += c == ']' ? 1 : -1);
        return (maxImbal + 1) / 2;
    }
};

int main() {
    Solution sol;
    string input = "]]][[[";
    int result = sol.minSwaps(input);
    cout << "Input: " << input << endl;
    cout << "Minimum Swaps Required: " << result << "\n";  // Output: 2
    return 0;
}
