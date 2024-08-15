#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five{0}, ten{0}, i{0};
        while (i < bills.size()) {
            if (bills[i] == 5) five++;
            else if (bills[i] == 10) { if (!five--) return false; ten++; }
            else if (ten && five--) ten--;
            else if (five >= 3) five -= 3; 
            else return false;
            i++;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Output for bills1: " << (solution.lemonadeChange(bills1) ? "true" : "false") << "\n";

    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Output for bills2: " << (solution.lemonadeChange(bills2) ? "true" : "false") << "\n";

    vector<int> bills3 = {5, 5, 5, 10, 10, 20, 20};
    cout << "Output for bills3: " << (solution.lemonadeChange(bills3) ? "true" : "false") << "\n";

    vector<int> bills4 = {5, 10, 10};
    cout << "Output for bills4: " << (solution.lemonadeChange(bills4) ? "true" : "false") << "\n";

    vector<int> bills5 = {5, 20, 5, 20};
    cout << "Output for bills5: " << (solution.lemonadeChange(bills5) ? "true" : "false") << "\n";

    return 0;
}
