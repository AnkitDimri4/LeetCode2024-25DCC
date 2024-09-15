#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        int b{0}, maxLen{0};
        m[0] = -1; 
        for (int i{0}; i < s.length(); ++i) {
            switch (s[i]) {
                case 'a': b ^= 1 << 0; break;
                case 'e': b ^= 1 << 1; break;
                case 'i': b ^= 1 << 2; break;
                case 'o': b ^= 1 << 3; break;
                case 'u': b ^= 1 << 4; break;
            }
            if (m.find(b) != m.end()) maxLen = max(maxLen, i - m[b]);
            else  m[b] = i;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s1 = "eleetminicoworoep";
    string s2 = "leetcodeisgreat";
    string s3 = "bcbcbc";

    cout << "Output for \"" << s1 << "\": " << sol.findTheLongestSubstring(s1) << endl;
    cout << "Output for \"" << s2 << "\": " << sol.findTheLongestSubstring(s2) << endl;
    cout << "Output for \"" << s3 << "\": " << sol.findTheLongestSubstring(s3) << endl;

    return 0;
}
