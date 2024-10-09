#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int o{0}, c{0};
        for (char ch : s) ch == '(' ? ++o : o ? --o : ++c;
        return o + c;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a parentheses string: ";
    cin >> input;
    int result = solution.minAddToMakeValid(input);
    cout << "Minimum add to make parentheses valid: " << result << "\n";
    return 0;
}
