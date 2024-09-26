#
---
# Intuition
To avoid **double booking** in the calendar, we must check for overlaps between the new event and previously booked events. For each booking request, we compare the new event's start and end times with existing events. If the time intervals of any existing event and the new event overlap, the new event can't be booked.

# Approach
The solution keeps track of booked events in a list. For each booking request, iterate through the list of booked events and check if there is an overlap. If the new event's start time is less than the existing event's end time, and its end time is greater than the existing event's start time, the events overlap. If no overlap is found, we can add the event to the calendar.

# Complexity
- **Time Complexity** $$O(n)$$ for each booking, where $$n$$ is the number of bookings made so far. Each booking involves checking for overlap with all previously booked events. **[Py3,cpp]**
- **Space Complexity** $$O(n)$$ since we store all booked events in a list.
#### ```Java```
> - **Time Complexity** $$O(\log n)$$ for each booking due to the **TreeMap** operations (insertion and key lookups).
> - **Space Complexity** $$O(n)$$ as we store all booked events in the **TreeMap**.
---

# Code
```cpp []
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
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class MyCalendar {
    private TreeMap<Integer, Integer> bookings;
    public MyCalendar() {
        bookings = new TreeMap<>();
    }
    public boolean book(int start, int end) {
        Integer floorKey = bookings.floorKey(start);
        if (floorKey != null && bookings.get(floorKey) > start) return false;
        Integer ceilingKey = bookings.ceilingKey(start);
        if (ceilingKey != null && ceilingKey < end) return false;
        bookings.put(start, end);
        return true;
    }
}
```
```python3 []
class MyCalendar:
    def __init__(self):
        self.bookings = []
    def book(self, start: int, end: int) -> bool:
        for b_start, b_end in self.bookings:
            if start < b_end and end > b_start:
                return False
        self.bookings.append((start, end))
        return True
```

---
- ![image.png](https://assets.leetcode.com/users/images/91f18e35-f031-4c21-b811-38a62735707b_1727318821.2271054.png)
- [O(n) | Easy Solution | Calendar Booking | C++ 54ms Beats 99.43% | Java Python3](https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26)

---
