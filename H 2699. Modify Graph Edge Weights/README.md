#
---

# Intuition
To solve the "Modify Graph Edge Weights" problem, we need to adjust the weights of edges with a value of **-1** so that the shortest path between the given source and destination nodes equals a target value. The key idea is to use Dijkstra's algorithm twice: first, to find the shortest path with current weights, and second, to determine if we can adjust the weights of edges with **-1** to achieve the target distance.

# Approach
1. **Graph Representation** Build an adjacency list from the given edges where each edge is represented with its end nodes and its index.
2. **First Dijkstra Run** Compute the shortest distance from the source to all nodes with current weights. This helps to determine how much distance needs to be added to reach the target distance.
3. **Second Dijkstra Run** Using the computed distances, adjust the weights of edges with **-1** such that the shortest path from source to destination equals the target distance.
4. **Final Adjustment** If the computed shortest distance equals the target, update the edge weights; otherwise, return an empty list indicating it's impossible.

# Complexity
- **Time Complexity** $$O((V + E) \log V)$$ where **V** is the number of vertices and **E** is the number of edges, due to the two Dijkstra runs.
- **Space Complexity** $$O(V + E)$$ for storing the graph and distances.

## Code
```cpp
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[src][0] = dist[src][1] = 0;
        dijkstra(adj, edges, dist, src, 0, 0);
        int diff = target - dist[dest][0];
        if (diff < 0) return {}; 
        dijkstra(adj, edges, dist, src, diff, 1);
        if (dist[dest][1] < target) return {}; 
        for (auto& e : edges) {
            if (e[2] == -1) e[2] = 1;
        }
        return edges;
    }
private:
    void dijkstra(const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& edges, vector<vector<int>>& dist, int src, int diff, int pass) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        dist[src][pass] = 0;
        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();
            if (currDist > dist[u][pass]) continue;
            for (auto& [v, idx] : adj[u]) {
                int weight = edges[idx][2] == -1 ? 1 : edges[idx][2];
                if (pass == 1 && edges[idx][2] == -1) {
                    int newWeight = diff + dist[v][0] - dist[u][1];
                    if (newWeight > weight) edges[idx][2] = weight = newWeight;
                }
                if (dist[v][pass] > dist[u][pass] + weight) {
                    dist[v][pass] = dist[u][pass] + weight;
                    pq.push({dist[v][pass], v});
                }
            }
        }
    }
};
static const auto io_sync = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
```

---

![image.png](https://assets.leetcode.com/users/images/1238beab-884f-4d09-b741-347c8c87d9ae_1724989721.4230602.png)

- [🌟Efficient Solution for "Modify Graph Edge Weights" | C++ | O((V + E) log V)](https://leetcode.com/problems/modify-graph-edge-weights/solutions/5800992/efficient-solution-for-modify-graph-edge-weights-c-o-v-e-log-v/)