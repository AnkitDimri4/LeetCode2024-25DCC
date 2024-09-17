from typing import List
from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words = s1.split() + s2.split()
        count = Counter(words)
        return [word for word, freq in count.items() if freq == 1]

if __name__ == "__main__":
    sol = Solution()
    s1 = "this apple is sweet"
    s2 = "this apple is sour"
    result = sol.uncommonFromSentences(s1, s2)
    
    print(" ".join(result))
