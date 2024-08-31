---
#
---
# Intuition
To solve this problem, the goal is to find the path with the highest success probability from a given start node to an end node. The approach is similar to finding the shortest path in a weighted graph, but instead of minimizing distance, we're maximizing the probability.

# Approach
**Graph Representation**: Represent the graph with an adjacency list where each node connects to its neighbors with a probability. Use a max-heap (priority queue) to explore nodes, prioritizing those with the highest probability. Apply a Dijkstra-like approach starting from the *start* node with a probability of 1.0. For each node, compute the new probability by multiplying the current probability with the edge's success probability, and if it's higher than the previously recorded probability for a neighbor, update it and push the neighbor onto the heap. Return the probability when the end node is reached, or 0.0 if no path exists.

# Complexity
- **Time Complexity** The time complexity is $$O((E + V) \log V)$$ where $$E$$ is the number of edges and $$V$$ is the number of vertices. The priority queue operations contribute to the logarithmic factor.
- **Space Complexity** The space complexity is $$O(V + E)$$ due to the storage of the graph and the max-heap.

# Code
```cpp []
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i{0}; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start});
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        while (!maxHeap.empty()) {
            auto [currentProb, node] = maxHeap.top();
            maxHeap.pop();
            if (node == end) return currentProb;
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = currentProb * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    maxHeap.push({newProb, neighbor});
                }
            }
        }
        return 0.0;
    }
};
```
```java []
class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<List<double[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph.get(u).add(new double[] {v, prob});
            graph.get(v).add(new double[] {u, prob});
        }
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) -> Double.compare(b[1], a[1]));
        maxHeap.offer(new double[] {start, 1.0});
        double[] maxProb = new double[n];
        Arrays.fill(maxProb, 0.0);
        maxProb[start] = 1.0;       
        while (!maxHeap.isEmpty()) {
            double[] top = maxHeap.poll();
            int node = (int) top[0];
            double currentProb = top[1];
            if (node == end) return currentProb;
            for (double[] neighborInfo : graph.get(node)) {
                int neighbor = (int) neighborInfo[0];
                double edgeProb = neighborInfo[1];
                double newProb = currentProb * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    maxHeap.offer(new double[] {neighbor, newProb});
                }
            }
        }
        return 0.0;
    }
```
```python []
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = [[] for _ in range(n)]
        for i in range(len(edges)):
            u, v = edges[i]
            prob = succProb[i]
            graph[u].append((v, prob))
            graph[v].append((u, prob))
        max_heap = [(-1.0, start)]
        max_prob = [0.0] * n
        max_prob[start] = 1.0
        while max_heap:
            current_prob, node = heapq.heappop(max_heap)
            current_prob = -current_prob
            if node == end:
                return current_prob
            for neighbor, edge_prob in graph[node]:
                new_prob = current_prob * edge_prob
                if new_prob > max_prob[neighbor]:
                    max_prob[neighbor] = new_prob
                    heapq.heappush(max_heap, (-new_prob, neighbor))
        return 0.0
```
![image.png](https://assets.leetcode.com/users/images/62eef349-b621-439e-9bfe-d3b7de4e2233_1724729024.6927826.png)


---
- [🌟 109ms | Dijkstra | C++ Solution for Path with Maximum Probability | Beats 96.70% |](https://leetcode.com/problems/path-with-maximum-probability/solutions/5696258/109ms-c-solution-for-path-with-maximum-probability-beats-96-70)
---
---
