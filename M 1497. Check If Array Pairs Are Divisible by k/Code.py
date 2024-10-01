class Solution:
    def canArrange(self, arr, k):
        freq = [0] * k
        for x in arr:
            freq[x % k] += 1
        if freq[0] % 2: 
            return False # Check pairs with sum divisible by k
        return all(freq[i] == freq[k - i] for i in range(1, k // 2 + 1)) # Check complementary pairs

sol = Solution()
arr = [1, 2, 3, 4, 5, 10, 6, 7, 8, 9]
k = 5
print(sol.canArrange(arr, k)) # Expected output: True
