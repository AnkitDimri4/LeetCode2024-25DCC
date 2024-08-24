class Solution:
    def nearestPalindromic(self, s: str) -> str:
        n = int(s)
        res = -1
        c = [10**(len(s) - 1) - 1, 10**len(s) + 1]
        p = s[:(len(s) + 1) // 2]
        i = -1
        while i <= 1:
            pal = str(int(p) + i)
            r = pal[:len(s) // 2][::-1]
            c.append(int(pal + r))
            i += 1
        i = 0
        while i < len(c):
            x = c[i]
            if x != n and (res == -1 or abs(x - n) < abs(res - n) or 
                            (abs(x - n) == abs(res - n) and x < res)):
                res = x
            i += 1
        return str(res)

sol = Solution()
print(sol.nearestPalindromic("123"))  # Output: "121"
print(sol.nearestPalindromic("1"))    # Output: "0"
