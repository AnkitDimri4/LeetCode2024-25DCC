class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        comb = s + "#" + rev
        kmp = [0] * len(comb)
        j = 0
        for i in range(1, len(comb)):
            j = kmp[i - 1]
            while j > 0 and comb[i] != comb[j]:
                j = kmp[j - 1]
            if comb[i] == comb[j]:
                j += 1
            kmp[i] = j
        return rev[:len(s) - kmp[-1]] + s


sol = Solution()
input_str = "aacecaaa"
output_str = sol.shortestPalindrome(input_str)
print(f"Input: {input_str}\nOutput: {output_str}")
