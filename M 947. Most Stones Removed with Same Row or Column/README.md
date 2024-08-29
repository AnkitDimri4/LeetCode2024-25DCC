#
---
# Intuition
To solve the "Most Stones Removed with Same Row or Column" problem, we can model this as a graph problem. Each stone can be considered as a node, and there's an edge between two nodes if the stones share the same row or column. The problem then reduces to finding the number of connected components in this graph. The maximum number of stones we can remove is the total number of stones minus the number of connected components.

# Approach
We use a Union-Find data structure to group stones that are in the same connected component (i.e., share the same row or column). Each stone is initially its own parent. As we iterate through the stones, we union the stones that share the same row or column. After processing all stones, the number of connected components will be the number of unique roots in our Union-Find structure. The result is then calculated as the total number of stones minus the number of connected components.

# Complexity
- **Time Complexity** The time complexity is $$O(n log n)$$ where **n** is the number of stones. This comes from the union-find operations.
- **Space Complexity** The space complexity is $$O(n)$$ due to the space required for the parent array in the union-find data structure.

## Code
```cpp []
class Solution {
public:
    int find(int x, unordered_map<int, int>& p) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }
    void unite(int x, int y, unordered_map<int, int>& p) {
        p[find(x, p)] = find(y, p);
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> p;
        for (auto& s : stones) {
            int r = s[0], c = ~(s[1]); 
            if (!p.count(r)) p[r] = r;
            if (!p.count(c)) p[c] = c;
            unite(r, c, p);
        }   
        unordered_set<int> roots;
        for (auto& s : stones) {
            roots.insert(find(s[0], p));
        }
        return stones.size() - roots.size();
    }
};
```

```java []
class Solution {
    public int removeStones(int[][] stones) {
        Map<Integer, Integer> parent = new HashMap<>();
        for (int[] stone : stones) {
            int r = stone[0];
            int c = ~stone[1];
            parent.putIfAbsent(r, r);
            parent.putIfAbsent(c, c);
            parent.put(find(parent, r), find(parent, c));
        }
        Set<Integer> roots = new HashSet<>();
        for (int[] stone : stones) {
            roots.add(find(parent, stone[0]));
        }
        
        return stones.length - roots.size();
    }
    private int find(Map<Integer, Integer> parent, int x) {
        if (parent.get(x) != x) {
            parent.put(x, find(parent, parent.get(x)));
        }
        return parent.get(x);
    }
}
```

```python []
class Solution:
    def find(self, parent, x):
        if parent[x] != x:
            parent[x] = self.find(parent, parent[x])
        return parent[x]
    def removeStones(self, stones: List[List[int]]) -> int:
        parent = {}
        for r, c in stones:
            c = ~c
            if r not in parent:
                parent[r] = r
            if c not in parent:
                parent[c] = c
            parent[self.find(parent, r)] = self.find(parent, c)
        roots = set()
        for r, _ in stones:
            roots.add(self.find(parent, r))
        return len(stones) - len(roots)
```
---
![image.png](https://assets.leetcode.com/users/images/a1bf495b-e1c0-4efe-88f5-4ed5c49ac12c_1724899266.0385528.png)

- [🌟Efficient Union-Find Solution for "Most Stones Removed with Same Row or Column" | C++ Java Py3 | O(n log n) |](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solutions/5800992/efficient-union-find-solution-for-most-stones-removed-with-same-row-or-column-c-java-py3-o-n-log-n/)
---