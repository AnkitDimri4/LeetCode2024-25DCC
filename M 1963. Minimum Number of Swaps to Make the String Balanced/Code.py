class Solution:
    def minSwaps(self, s: str) -> int:
        u = 0  
        for c in s:
            u += 1 if c == '[' else -1 if u > 0 else 0 
        return (u + 1) // 2 

if __name__ == "__main__":
    sol = Solution()
    input_str = "]]][[["
    result = sol.minSwaps(input_str)
    print("Input:", input_str)
    print("Minimum Swaps Required:", result)  # Output: 2
