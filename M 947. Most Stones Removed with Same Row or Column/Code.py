class Solution:
    def find(self, x, p):
        if p[x] != x:
            p[x] = self.find(p[x], p)
        return p[x]
    
    def unite(self, x, y, p):
        p[self.find(x, p)] = self.find(y, p)
    
    def removeStones(self, stones):
        p = {}
        for r, c in stones:
            c = ~c
            if r not in p:
                p[r] = r
            if c not in p:
                p[c] = c
            self.unite(r, c, p)
        roots = {self.find(r, p) for r, _ in stones}
        return len(stones) - len(roots)
sol = Solution()
stones = [[0,0],[2,2],[10000,2]]
result = sol.removeStones(stones)
print(result)  # Output: 1
