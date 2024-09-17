#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        for (stringstream ss(s1 + " " + s2); ss >> s1;) m[s1]++;
        vector<string> r;
        for (auto& [k, v] : m) if (v == 1) r.push_back(k);
        return r;
    }
};

int main() {
    Solution sol;
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    vector<string> result = sol.uncommonFromSentences(s1, s2);
    
    for (const auto &word : result) cout << word << " ";
    return 0;
}
