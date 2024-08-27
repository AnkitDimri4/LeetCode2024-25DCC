import heapq
from typing import List
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
n = 3
edges = [[0, 1], [1, 2], [0, 2]]
succProb = [0.5, 0.5, 0.2]
start = 0
end = 2

sol = Solution()
result = sol.maxProbability(n, edges, succProb, start, end)
print(f"Output: {result:.5f}")  # Output: 0.25000
