#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int stores, vector<int>& qty) {
        int low{1}, high = *max_element(qty.begin(), qty.end());
        while (low < high) {
            int mid = (low + high) / 2, needed{0};
            for (int q : qty) needed += (q + mid - 1) / mid;
            if (needed <= stores) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> quantities1 = {11, 6};
    int stores1 = 6;
    cout << "Output 1: " << sol.minimizedMaximum(stores1, quantities1) << "\n";  // Output: 3

    vector<int> quantities2 = {15, 10, 10};
    int stores2 = 7;
    cout << "Output 2: " << sol.minimizedMaximum(stores2, quantities2) << "\n";  // Output: 5

    vector<int> quantities3 = {100000};
    int stores3 = 1;
    cout << "Output 3: " << sol.minimizedMaximum(stores3, quantities3) << "\n";  // Output: 100000
    return 0;
}
