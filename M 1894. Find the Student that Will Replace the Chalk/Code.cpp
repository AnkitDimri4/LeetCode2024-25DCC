#include <iostream>
#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& ch, int k) {
        long long total{0};
        for (int c : ch) total += c;
        k %= total;
        int i{0};s
        while (k >= ch[i]) k -= ch[i++];
        return i;
    }
};

int main() {
    Solution sol;
    std::vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    std::cout << "Output for chalk1: " << sol.chalkReplacer(chalk1, k1) << std::endl; // Output: 0
    
    std::vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    std::cout << "Output for chalk2: " << sol.chalkReplacer(chalk2, k2) << std::endl; // Output: 1

    return 0;
}
