#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
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
int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0, end = 2;
    
    double result = sol.maxProbability(n, edges, succProb, start, end);
    cout << "Output: " << result << "\n";  // Output: 0.25000
    
    return 0;
}
