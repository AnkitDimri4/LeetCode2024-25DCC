#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;
        vector<int> kmp(comb.size());
        for (int i{1}, j{0}; i < comb.size(); ++i) {
            j = kmp[i - 1];
            while (j > 0 && comb[i] != comb[j]) j = kmp[j - 1];
            if (comb[i] == comb[j]) ++j;
            kmp[i] = j;
        }
        return rev.substr(0, s.size() - kmp.back()) + s;
    }
};

int main() {
    Solution sol;
    string input = "aacecaaa";
    string output = sol.shortestPalindrome(input);
    cout << "Input: " << input << "\nOutput: " << output << endl;
    return 0;
}
