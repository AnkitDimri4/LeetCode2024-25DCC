class Solution:
    def maxPoints(self, pts):
        r, n = 1, len(pts[0])
        prev = pts[0]
        while r < len(pts):
            curr = prev[:]
            for c in range(1, n):
                curr[c] = max(curr[c], curr[c-1] - 1)
            for c in range(n-2, -1, -1):
                curr[c] = max(curr[c], curr[c+1] - 1)
            prev = [curr[c] + pts[r][c] for c in range(n)]
            r += 1
        return max(prev)

if __name__ == "__main__":
    solution = Solution()

    points1 = [[1, 2, 3], [1, 5, 1], [3, 1, 1]]
    print("Maximum points for points1:", solution.maxPoints(points1))

    points2 = [[1, 5], [2, 3], [4, 2]]
    print("Maximum points for points2:", solution.maxPoints(points2))
