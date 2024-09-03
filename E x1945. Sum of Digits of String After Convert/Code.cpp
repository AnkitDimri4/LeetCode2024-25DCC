#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for (char c : s) num += to_string(c - 'a' + 1);
        while (k--) {
            int sum = 0;
            for (char d : num) sum += d - '0';
            num = to_string(sum);
        }
        return stoi(num);
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    int k = 2;
    int result = sol.getLucky(s, k);
    cout << "Output: " << result << endl; // Output: 6
    return 0;
}
