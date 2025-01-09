from typing import List

class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(word.startswith(pref) for word in words)  # Count words starting with pref

# Example usage
if __name__ == "__main__":
    words = ["pay", "attention", "practice", "attend"]
    pref = "at"
    sol = Solution()
    print(f"Count of words with prefix \"{pref}\": {sol.prefixCount(words, pref)}")
