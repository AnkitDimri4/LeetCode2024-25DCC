#
---
# Intuition
The goal is to find the minimum time difference between any two time points in a list. Since the time points are given in a 24-hour "HH:MM" format, we first convert them to minutes (from the start of the day). Then, after sorting the time points, we can find the minimum difference by checking consecutive time points. Additionally, we must also check the difference between the first and last time points due to the circular nature of the clock.

# Approach
Convert each time point from "HH:MM" format into total minutes from midnight, then sort these values. Calculate the minimum difference between consecutive times in the sorted list, but also consider the circular nature of the clock by checking the difference between the last time point and the first (i.e., the difference between the last time of the day and midnight on the next day). This make sures the smallest difference is captured, even across midnight.

# Complexity:
- **Time Complexity** $$O(n \log n)$$, where $$n$$ is the number of time points, due to the sorting step.
- **Space Complexity** $$O(n)$$, for storing the converted time points.

# Code
```cpp []
class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> m;
        for (auto& s : t) m.push_back(stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
        sort(m.begin(), m.end());
        int minDiff = 1440 + m[0] - m.back(); 
        for (int i{1}; i < m.size(); ++i) minDiff = min(minDiff, m[i] - m[i - 1]);
        return minDiff;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```java []
class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> minutes = new ArrayList<>();
        for (String t : timePoints) {
            String[] hm = t.split(":");
            int mins = Integer.parseInt(hm[0]) * 60 + Integer.parseInt(hm[1]);
            minutes.add(mins);
        }
        Collections.sort(minutes);
        int minDiff = 1440 + minutes.get(0) - minutes.get(minutes.size() - 1); 
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = Math.min(minDiff, minutes.get(i) - minutes.get(i - 1));
        }
        return minDiff;
    }
}
```

```python []
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minutes = []
        for t in timePoints:
            h, m = map(int, t.split(":"))
            minutes.append(h * 60 + m)
        minutes.sort()
        minDiff = 1440 + minutes[0] - minutes[-1] 
        for i in range(1, len(minutes)):
            minDiff = min(minDiff, minutes[i] - minutes[i - 1])
        return minDiff
```

---
- 
![image.png](https://assets.leetcode.com/users/images/f3085d70-b089-46f2-9607-6cdb79255b47_1726459098.5909245.png)
- [Easy Solution | C++ 5ms Beats 96.71% Java Py3 | O(nlogn)](https://leetcode.com/problems/minimum-time-difference/description/)

---