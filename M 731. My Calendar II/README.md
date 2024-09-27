# 
---
> # Intuition
The goal is to implement a calendar that allows double bookings but prevents triple bookings. This can be efficiently managed by maintaining two lists: one for all bookings and another for overlaps. By checking existing overlaps before adding a new booking, we can make sure no triple booking occurs.

> # Approach
We utilize two vectors (or lists): one to store all bookings and another to track overlaps. When booking a new event, we first check against the overlaps to make sure no triple bookings occur. If it passes, we then check the existing bookings to find and store any new overlaps before adding the new booking to the list.

> # Complexity
- **Time Complexity** $$O(n)$$, where n is the number of existing bookings, as we potentially check all existing bookings and overlaps.
- **Space Complexity** $$O(n)$$ for storing the bookings and overlaps.
---
> # Code
```cpp []
class MyCalendarTwo {
    vector<pair<int,int>> b, o;
public:
    MyCalendarTwo() {}
    bool book(int s, int e) {
        for(auto& [start, end] : o) {
            if (s < end && e > start) return false;
        }
        for(auto& [start, end] : b) {
            if (s < end && e > start)  o.push_back({max(s, start), min(e, end)});
        }
        b.emplace_back(s, e);
        return true;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
class MyCalendarTwo {
    private List<int[]> bookings, overlaps;
    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        overlaps = new ArrayList<>();
    }
    public boolean book(int start, int end) {
        for (int[] o : overlaps) {
            if (start < o[1] && end > o[0]) return false;
        }
        for (int[] b : bookings) {
            if (start < b[1] && end > b[0]) {
                overlaps.add(new int[]{Math.max(start, b[0]), Math.min(end, b[1])});
            }
        }
        bookings.add(new int[]{start, end});
        return true;
    }
}
```
```python3 []
class MyCalendarTwo:
    def __init__(self):
        self.bookings = []
        self.overlaps = []
    def book(self, start: int, end: int) -> bool:
        for o in self.overlaps:
            if start < o[1] and end > o[0]:
                return False
        for b in self.bookings:
            if start < b[1] and end > b[0]:
                self.overlaps.append([max(start, b[0]), min(end, b[1])])
        self.bookings.append([start, end])
        return True
```
---
> - ![image.png](https://assets.leetcode.com/users/images/8a5c4bcf-a9d1-4ae4-846e-b42b1bb99083_1727405543.5661209.png)
> - [💡| C++ 51ms Beats 99.90% | Easy Solution | My Calendar II Java Py3](https://leetcode.com/problems/my-calendar-ii/description/)

---