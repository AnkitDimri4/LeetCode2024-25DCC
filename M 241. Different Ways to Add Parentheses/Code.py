class Solution:
    def diffWaysToCompute(self, expr: str) -> list[int]:
        if expr.isdigit():
            return [int(expr)]
        res = []
        for i, c in enumerate(expr):
            if c in "+-*":
                left = self.diffWaysToCompute(expr[:i])
                right = self.diffWaysToCompute(expr[i + 1:])
                res.extend(l + r if c == '+' else l - r if c == '-' else l * r for l in left for r in right)
        return res

if __name__ == "__main__":
    sol = Solution()
    expression = "2*3-4*5"
    results = sol.diffWaysToCompute(expression)
    print("Output:", results)
