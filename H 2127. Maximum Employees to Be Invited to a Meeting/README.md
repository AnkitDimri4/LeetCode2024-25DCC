
---

### **Problem Overview**  

The problem requires determining the maximum number of employees who can be invited to a meeting. Each employee has a **favorite person**, and they will only attend if seated next to that person at a circular table. The input is a **favorite** array where $$favorite[i]$$ indicates the favorite person of employee **i**. The task is to arrange the employees optimally to maximize attendance.

---

### **Intuition** 🧩

This can be viewed as a **directed graph** problem -
- Each employee is a **node**.  
- Each "favorite" relationship is a **directed edge**.  

The challenge is to handle two cases -  
1. **Cycles** Employees forming a closed loop of "favorite" relationships (e.g., $$[1,2,0]$$).  
2. **Chains ending in cycles** Chains of employees leading into cycles or two-person mutual dependencies (e.g., $$[2,2,1,2]$$ where chains extend to the cycle).  

---

### **Approach**  🎯

1. **Graph Representation**  Treat the **favorite** array as a directed graph.  
2. **In-degree Calculation**  Compute the in-degrees for each node to identify nodes not part of cycles.  
3. **Depth Calculation**  Perform BFS to determine the lengths of chains ending in cycles.  

4. **Cycle Analysis**  
   - Identify the **maximum cycle length** for cycles longer than two.  
   - Handle **two-person cycles** by summing their chain contributions.  

5. **Return the Result**  The answer is the maximum of the **longest cycle** and the **total length of two-person cycle contributions**.

---
### **Complexity**  📊

- **Time Complexity** $$O(n)$$  
  - Each node and edge is processed exactly once.  

- **Space Complexity** $$O(n)$$ 
  - Arrays for in-degree, depth, and the BFS queue.
---

### **Code**   💻

```cpp
class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<int> inDeg(n, 0), depth(n, 1);
        for (int i{0}; i < n; ++i) inDeg[fav[i]]++;
        queue<int> q;
        for (int i{0}; i < n; ++i) if (inDeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int nxt = fav[cur];
            depth[nxt] = max(depth[nxt], depth[cur] + 1);
            if (--inDeg[nxt] == 0) q.push(nxt);
        }
        int maxCycle{0}, twoCycleSum{0};
        for (int i{0}; i < n; ++i) {
            if (inDeg[i] == 0) continue;
            int len{0}, cur = i;
            while (inDeg[cur] != 0) {
                inDeg[cur]=0;
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
static auto init = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();
```

---
> - **C++**
> ![image.png](https://assets.leetcode.com/users/images/2584c076-616f-444c-a9e6-12c0c632c620_1737853037.8886988.png)
[💡 | O(n) | C++ | Beats 100.00% | Graph Analysis + Depth Tracking 🧠](https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6329632/o-n-c-beats-100-00-graph-analysis-depth-tracking)

---

