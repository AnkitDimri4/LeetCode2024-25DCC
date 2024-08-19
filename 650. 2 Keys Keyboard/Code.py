class Solution:
    def minSteps(self, n: int) -> int:
        s = 0
        i = 2
        while i * i <= n:
            while n % i == 0:
                s += i
                n //= i
            i += 1
        if n > 1:
            s += n
        return s

if __name__ == "__main__":
    sol = Solution()
    n = 3  # Example input
    print(f"Input: n = {n}")
    print(f"Output: {sol.minSteps(n)}")
