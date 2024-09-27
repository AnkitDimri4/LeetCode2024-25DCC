#include <iostream>
#include <vector>
using namespace std;

class MyCalendarTwo {
    vector<pair<int, int>> b, o; // b for bookings, o for overlaps
public:
    MyCalendarTwo() {}

    bool book(int s, int e) {
        for (auto& [start, end] : o) { // Check overlaps
            if (s < end && e > start) return false;
        }
        for (auto& [start, end] : b) { // Store new overlaps
            if (s < end && e > start) {
                o.push_back({max(s, start), min(e, end)});
            }
        }
        b.emplace_back(s, e); // Store the new booking
        return true;
    }
};

int main() {
    MyCalendarTwo myCalendar;
    cout << myCalendar.book(10, 20) << "\n"; // Output: 1 (true)
    cout << myCalendar.book(15, 25) << "\n"; // Output: 1 (true)
    cout << myCalendar.book(20, 30) << "\n"; // Output: 1 (true)
    cout << myCalendar.book(5, 15) << "\n";  // Output: 0 (false, triple booking)
    return 0;
}
