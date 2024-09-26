#include <iostream>
#include <vector>
using namespace std;

class MyCalendar {
    vector<pair<int, int>> bks;
public:
    bool book(int s, int e) {
        for (auto& [bs, be] : bks)
            if (s < be && bs < e) return false;
        bks.push_back({s, e});
        return true;
    }
};

int main() {
    MyCalendar myCalendar;
    cout << (myCalendar.book(10, 20) ? "true" : "false") << "\n"; // true
    cout << (myCalendar.book(15, 25) ? "true" : "false") << "\n"; // false
    cout << (myCalendar.book(20, 30) ? "true" : "false") << "\n"; // true
    return 0;
}
