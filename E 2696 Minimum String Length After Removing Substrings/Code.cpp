#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && ((c == 'B' && stk.top() == 'A') || (c == 'D' && stk.top() == 'C')))
                stk.pop();
            else 
                stk.push(c);
        }
        return stk.size();
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = solution.minLength(s);
    cout << "The minimum possible length of the resulting string is: " << result << "\n";

    return 0;
}
