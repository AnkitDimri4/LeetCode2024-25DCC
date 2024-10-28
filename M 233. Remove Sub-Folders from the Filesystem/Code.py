class Solution:
    def removeSubfolders(self, folder: list[str]) -> list[str]:
        folder.sort()
        result = []
        for dir in folder:
            if not result or not dir.startswith(result[-1] + '/'):
                result.append(dir)
        return result
solution = Solution()
folder1 = ["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]
print(solution.removeSubfolders(folder1))  # Output: ["/a", "/c/d", "/c/f"]
folder2 = ["/a", "/a/b/c", "/a/b/d"]
print(solution.removeSubfolders(folder2))  # Output: ["/a"]
