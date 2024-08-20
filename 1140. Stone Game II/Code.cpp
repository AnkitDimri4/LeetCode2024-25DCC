#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int stoneGameII(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> sum(n + 1);
        int i{n - 1};
        while (i >= 0) sum[i] = p[i] + (i + 1 < n ? sum[i + 1] : 0), --i;
        i = n - 1;
        while (i >= 0) {
            int m{1};
            while (m <= n) {
                int x{1};
                while (x <= min(2 * m, n - i)) {
                    dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(m, x)]);
                    ++x;
                }
                ++m;
            }
            --i;
        }
        return dp[0][1];
    }
};
int main() {
    Solution sol;
    vector<int> piles = {2, 7, 9, 4, 4};
    int result = sol.stoneGameII(piles);
    printf("Maximum stones Alice can get: %d\n", result);
    return 0;
}
