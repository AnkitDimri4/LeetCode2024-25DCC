#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<int> inDeg(n, 0), depth(n, 1);

        // Calculate in-degrees
        for (int i = 0; i < n; ++i) inDeg[fav[i]]++;

        // Process nodes with zero in-degree
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int nxt = fav[cur];
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (--inDeg[nxt] == 0) q.push(nxt);
        }

        int maxCycle = 0, twoCycleSum = 0;

        // Detect cycles
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) continue;

            int len = 0, cur = i;
            while (inDeg[cur] != 0) {
                inDeg[cur] = 0;
                len++;
                cur = fav[cur];
            }

            if (len == 2) {
                twoCycleSum += depth[i] + depth[fav[i]];
            } else {
                maxCycle = max(maxCycle, len);
            }
        }

        return max(maxCycle, twoCycleSum);
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> favorite1 = {2, 2, 1, 2};
    vector<int> favorite2 = {1, 2, 0};
    vector<int> favorite3 = {3, 0, 1, 4, 1};

    // Example outputs
    cout << "Maximum invitations for favorite1: " << solution.maximumInvitations(favorite1) << "\n";
    cout << "Maximum invitations for favorite2: " << solution.maximumInvitations(favorite2) << "\n";
    cout << "Maximum invitations for favorite3: " << solution.maximumInvitations(favorite3) << "\n";

    return 0;
}
