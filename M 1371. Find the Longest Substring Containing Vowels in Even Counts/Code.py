class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        m = {0: -1}
        b, maxLen = 0, 0
        for i, char in enumerate(s):
            if char == 'a': b ^= 1 << 0
            elif char == 'e': b ^= 1 << 1
            elif char == 'i': b ^= 1 << 2
            elif char == 'o': b ^= 1 << 3
            elif char == 'u': b ^= 1 << 4
            
            if b in m:
                maxLen = max(maxLen, i - m[b])
            else:
                m[b] = i
        return maxLen


sol = Solution()
s1 = "eleetminicoworoep"
s2 = "leetcodeisgreat"
s3 = "bcbcbc"

print(f"Output for \"{s1}\": {sol.findTheLongestSubstring(s1)}")
print(f"Output for \"{s2}\": {sol.findTheLongestSubstring(s2)}")
print(f"Output for \"{s3}\": {sol.findTheLongestSubstring(s3)}")
