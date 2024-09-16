#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> m;
        for (auto& s : t) 
            m.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
        sort(m.begin(), m.end());
        int minDiff = 1440 + m[0] - m.back(); 
        for (int i{1}; i < m.size(); ++i) 
            minDiff = min(minDiff, m[i] - m[i - 1]);
        return minDiff;
    }
};

int main() {
    Solution sol;
    vector<string> timePoints1 = {"23:59", "00:00"};
    vector<string> timePoints2 = {"00:00", "23:59", "00:00"};
    
    cout << "Minimum Difference (Example 1): " << sol.findMinDifference(timePoints1) << endl; // Output: 1
    cout << "Minimum Difference (Example 2): " << sol.findMinDifference(timePoints2) << endl; // Output: 0
    
    return 0;
}
