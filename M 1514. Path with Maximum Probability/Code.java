import java.util.*;
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
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 3;
        int[][] edges = {{0, 1}, {1, 2}, {0, 2}};
        double[] succProb = {0.5, 0.5, 0.2};
        int start = 0, end = 2;

        double result = sol.maxProbability(n, edges, succProb, start, end);
        System.out.printf("Output: %.5f%n", result);  // Output: 0.25000
    }
}
