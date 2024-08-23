import re
from math import gcd

class Solution:
    def fractionAddition(self, expr: str) -> str:
        num, den = 0, 1
        for n, d in re.findall(r'([+-]?\d+)/(\d+)', expr):
            n, d = int(n), int(d)
            num = num * d + n * den
            den *= d
            g = gcd(abs(num), den)
            num //= g
            den //= g
        return f'{num}/{den}'

sol = Solution()
print(sol.fractionAddition("1/3-1/2"))  # Output: "-1/6"
print(sol.fractionAddition("5/2+1/3"))  # Output: "11/6"
