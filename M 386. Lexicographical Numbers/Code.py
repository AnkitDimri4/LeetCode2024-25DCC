class Solution:
    def lexicalOrder(self, n: int) -> list[int]:
        res = []
        for i in range(1, 10):
            self.add(i, n, res)
        return res
    
    def add(self, x: int, n: int, res: list[int]):
        if x > n:
            return
        res.append(x)
        for i in range(10):
            if x * 10 + i > n:
                break
            self.add(x * 10 + i, n, res)

if __name__ == "__main__":
    sol = Solution()
    n = 13
    result = sol.lexicalOrder(n)
    print(result)
