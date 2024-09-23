#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size(), m;
        vector<int> dp(n + 1);
        for (int i{1}; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; 
            for (const string& word : d) {
                m = word.size();
                if (i >= m && s.substr(i - m, m) == word) dp[i] = min(dp[i], dp[i - m]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    cout << "Minimum extra characters: " << sol.minExtraChar(s, dictionary) << endl;
    return 0;
}
