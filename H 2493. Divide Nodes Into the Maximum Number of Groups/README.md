---
### 🔹 **Intuition**   🧩
The problem requires us to divide the nodes of a graph into groups such that adjacent nodes belong to consecutive groups. This hints at a **bipartite graph** structure where nodes must be assigned alternating colors (0 and 1). If the graph contains **odd-length cycles**, it is impossible to divide the nodes as required.   
- **Checking if the graph is bipartite** using **DFS** (if not, return $$-1$$).  
- **Finding the largest depth** in each connected component using **BFS**.  
- **Summing up the depths** of all components to get the **maximum number of groups**.
  
---

### 🔹 **Approach**   🎯


- **Graph Construction**
- 
   - Build an adjacency list from the given $$edges$$.  
- **Check Bipartiteness using DFS**  
   - If a node is unvisited, start a DFS to assign colors ($$0$$ or $$1$$).  
   - If a conflict arises (same color assigned to adjacent nodes), return $$-1$$ as the graph is not bipartite.  
- **Find Maximum Depth in Each Component using BFS**  
   - For each connected component, perform BFS from each node to determine the **maximum depth**.  
   - The $$largest depth$$ found across all BFS runs is the number of groups for that component.  
- **Sum the Maximum Depths**  
   - The sum of the depths across all connected components gives the final answer.

---



### 🔹 **Complexity Analysis**  📊

- **Graph Construction** $$O(n + m)$$ (where $$n$$ is the number of nodes, $$m$$ is the number of edges)
- **DFS for Bipartiteness Check** $$O(n + m)$$  
- **BFS for Maximum Depth** $$O(n + m)$$  
  - Note: Each BFS operation runs across all edges and nodes in a component **once**. Even though we perform BFS from every node in a component, **each edge** is visited only once per component. Hence, the complexity of BFS remains $$O(n + m)$$ for the entire graph.
- **Overall Complexity** $$O(n + m)$$  
---

### 🔹 **Code**  💻

```cpp []
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> color(n, -1);
        vector<vector<int>> components;
        for (int i{0}; i < n; ++i) {
            if (color[i] == -1) {
                components.emplace_back();
                if (!dfs(i, 0, adj, color, components.back())) return -1;
            }
        }
        int maxGroups{0};
        for (const auto& comp : components) {
            maxGroups += bfsMaxDepth(comp, adj);
        }
        return maxGroups;
    }
private:
    bool dfs(int node, int col, const vector<vector<int>>& adj, vector<int>& color, vector<int>& comp) {
        color[node] = col;
        comp.push_back(node);
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) return false;
            if (color[neighbor] == -1 && !dfs(neighbor, 1 - col, adj, color, comp)) return false;
        }
        return true;
    }
    int bfsMaxDepth(const vector<int>& comp, const vector<vector<int>>& adj) {
        int maxDepth{0};
        for (int start : comp) {
            vector<int> depth(adj.size(), -1);
            vector<int> queue = {start};
            depth[start]{0};
            for (size_t i{0}; i < queue.size(); ++i) {
                int node = queue[i];
                for (int neighbor : adj[node]) {
                    if (depth[neighbor] == -1) {
                        depth[neighbor] = depth[node] + 1;
                        queue.push_back(neighbor);
                    }
                }
            }
            maxDepth = max(maxDepth, *max_element(depth.begin(), depth.end()));
        }
        return maxDepth + 1;
    }
};
```
---
> **C++**
> ![image.png](https://assets.leetcode.com/users/images/0e794f9c-8c47-4eb2-90e5-56a3e63e8be0_1738197645.6182022.png)
[💡 | O(n + m) | C++ | Graph, BFS, DFS, Bipartite Check, Maximum Depth](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/solutions/6346238/on-m-c-graph-bfs-dfs-by-user4612mw-1o05)

---
---














































