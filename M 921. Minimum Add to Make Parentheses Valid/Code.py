class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        o = c = 0
        for ch in s:
            if ch == '(':
                o += 1
            elif o > 0:
                o -= 1
            else:
                c += 1
        return o + c

if __name__ == "__main__":
    solution = Solution()
    s = input("Enter a parentheses string: ")
    result = solution.minAddToMakeValid(s)
    print(f"Minimum add to make parentheses valid: {result}")
