---
### **Problem Overview**  🎯
In this problem, we are given a graph that started as a tree with $$n$$ nodes labeled from $$1$$ to $$n$$, with one additional edge added. The task is to find and return the redundant edge that, when removed, will restore the graph to a tree structure.

---

### **Intuition** 🧩

A tree is an acyclic connected graph. Adding an extra edge to a tree creates exactly one cycle. To identify this redundant edge, we can utilize the **Union-Find** data structure, which efficiently tracks connected components and detects cycles in an undirected graph.

---

### **Approach** 🎯


1. **Union-Find Initialization**
    Initialize the $$parent$$ array where each node is its own parent.
   - Initialize the $$rank$$ array to keep track of the tree depth for union by rank optimization.

2. **Processing Edges**
   - Iterate through each edge in the graph.
   - For each edge $$(u, v)$$, perform the union operation:
     - If $$u$$ and $$v$$ are already connected (i.e., they have the same root), then adding this edge would form a cycle, making it the redundant edge.
     - If they are not connected, unite them by updating their parent and rank accordingly.

3. **Cycle Detection**
   - If a cycle is detected during the union operation, return the current edge as the redundant connection.

---

### **Complexity Analysis** 📊

- **Time Complexity** Each $$find$$ and $$union$$ operation has an amortized time complexity of $$O(\alpha(n))$$, where $$\alpha$$ is the inverse Ackermann function, which grows very slowly and is practically constant for all reasonable n. Therefore, processing all edges results in a time complexity of $$O(n \cdot \alpha(n))$$, which is effectively $$O(n)$$.

- **Space Complexity** The space complexity is $$O(n)$$ due to the storage required for the $$parent$$ and $$rank$$ arrays.

---

### **Code Implementation** 💻

```cpp []
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    bool unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;
        if (rank[rootU] < rank[rootV]) swap(rootU, rootV);
        parent[rootV] = rootU;
        if (rank[rootU] == rank[rootV]) rank[rootU]++;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        for (const auto& edge : edges) {
            if (!uf.unite(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
```

---

> **C++**
> ![image.png](https://assets.leetcode.com/users/images/a3d10f58-df43-4fa4-ab8a-5f41fba58354_1738114294.6895206.png)
[💡 | O(n) | C++ 0ms Beats 100.00% | Disjoint Set Union (DSU)  🧠](https://leetcode.com/problems/redundant-connection/solutions/6342024/o-n-c-0ms-beats-100-00-disjoint-set-union-dsu)

---
--- 
