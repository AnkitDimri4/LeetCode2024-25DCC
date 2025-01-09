#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return count_if(words.begin(), words.end(), [&](const string& word) {
            return word.find(pref) == 0; // Check if pref is a prefix
        });
    }
};

int main() {
    vector<string> words = {"pay", "attention", "practice", "attend"};
    string pref = "at";
    Solution sol;
    cout << "Count of words with prefix \"" << pref << "\": " << sol.prefixCount(words, pref) << "\n";
    return 0;
}
