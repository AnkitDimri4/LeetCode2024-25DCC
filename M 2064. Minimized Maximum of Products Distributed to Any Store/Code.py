import math
from typing import List

class Solution:
    def _binarySearchSolution(self, stores: int, products: List[int]) -> int:
        products.sort(reverse=True)
        left, right = 1, products[0]
        while left <= right:
            mid = (left + right) // 2
            extra = stores - len(products)
            for p in products:
                extra -= math.ceil(p / mid) - 1
                if extra < 0: break
            if extra < 0:
                left = mid + 1
            else:
                right = mid - 1
                res = mid
        return res

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        return max(quantities) if n == len(quantities) else self._binarySearchSolution(n, quantities)

# Test cases
sol = Solution()

# Test case 1
quantities1 = [11, 6]
stores1 = 6
print("Output 1:", sol.minimizedMaximum(stores1, quantities1))  # Output: 3

# Test case 2
quantities2 = [15, 10, 10]
stores2 = 7
print("Output 2:", sol.minimizedMaximum(stores2, quantities2))  # Output: 5

# Test case 3
quantities3 = [100000]
stores3 = 1
print("Output 3:", sol.minimizedMaximum(stores3, quantities3))  # Output: 100000
