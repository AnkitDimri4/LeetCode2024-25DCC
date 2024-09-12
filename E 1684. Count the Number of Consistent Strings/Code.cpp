#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allowedSet[26] = {};
        for (char c : allowed) allowedSet[c - 'a'] = true;  
        int count{0};
        for (const auto& word : words) 
            count += all_of(word.begin(), word.end(), [&](char c){ return allowedSet[c - 'a']; });
        return count;
    }
};

int main() {
    Solution solution;
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
    cout << "Output: " << solution.countConsistentStrings(allowed, words) << endl; // Output: 2
    return 0;
}
