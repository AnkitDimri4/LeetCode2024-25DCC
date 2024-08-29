import java.util.*;
class Solution {
    public int find(int x, Map<Integer, Integer> p) {
        if (p.get(x) != x) {
            p.put(x, find(p.get(x), p));
        }
        return p.get(x);
    }
    public void unite(int x, int y, Map<Integer, Integer> p) {
        p.put(find(x, p), find(y, p));
    }
    public int removeStones(int[][] stones) {
        Map<Integer, Integer> p = new HashMap<>();
        for (int[] s : stones) {
            int r = s[0], c = ~s[1];
            p.putIfAbsent(r, r);
            p.putIfAbsent(c, c);
            unite(r, c, p);
        }
        Set<Integer> roots = new HashSet<>();
        for (int[] s : stones) {
            roots.add(find(s[0], p));
        }
        return stones.length - roots.size();
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] stones = {{0,0},{2,2},{10000,2}};
        int result = sol.removeStones(stones);
        System.out.println(result);  // Output: 1
    }
}
