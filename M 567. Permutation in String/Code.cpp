#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string p, string s) {
        if (p.size() > s.size()) return false;
        vector<int> f1(26), f2(26);
        for (int i{0}; i < p.size(); ++i) f1[p[i] - 'a']++, f2[s[i] - 'a']++;
        for (int i = p.size(); i < s.size(); ++i) {
            if (f1 == f2) return true;
            f2[s[i] - 'a']++, f2[s[i - p.size()] - 'a']--;
        }
        return f1 == f2;
    }
};

int main() {
    Solution sol;
    string p = "ab"; 
    string s = "eidbaooo"; 
    bool result = sol.checkInclusion(p, s);
    cout << (result ? "true" : "false") << "\n"; // Output: true
    return 0;
}
