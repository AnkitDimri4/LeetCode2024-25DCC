
#
---
> # Intuition
To remove sub-folders efficiently, we sort the folders lexicographically to make sure that sub-folders appear right after their parent folders. By comparing each folder with the last added folder in the result, we can identify and skip sub-folders without extra nested loops.

> # Approach
First, we sort the list of folders in $$O(n log n)$$ time. After sorting, we iterate through the sorted folders list to compare each folder with the last folder in the result list, checking if it is a sub-folder. We do this by confirming the current folder starts with the previous folder path, followed by a $$/$$. This way, we make sure only root-level folders are added to the result, skipping any sub-folders. Each comparison takes $$O(m)$$ time, where $$m$$ is the average length of folder names. Thus, the complete time complexity is $$O(n log n + n * m)$$.

> # Complexity
- **Time Complexity** $$O(n log n + n * m)$$, where $$n$$ is the number of folders, and $$m$$ is the average folder name length.
- **Space Complexity** $$O(n)$$ for storing the result.
> # Code
```cpp []
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (auto& dir : folder) {
            if (result.empty() || dir.compare(0, result.back().size(), result.back()) != 0 || dir[result.back().size()] != '/') {
                result.push_back(move(dir));
            }
        }
        return result;
    }
};
```

```python []
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        result = []
        for dir in folder:
            if not result or not dir.startswith(result[-1] + '/'):
                result.append(dir)
        return result
```
 
```java []
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> result = new ArrayList<>();
        for (String dir : folder) {
            if (result.isEmpty() || !dir.startsWith(result.get(result.size() - 1) + "/")) {
                result.add(dir);
            }
        }
        return result;
    }
}
```
---
> **CPP**
> ![image.png](https://assets.leetcode.com/users/images/3c2777fb-90a7-4789-b5ad-68149ff4c854_1729828210.081669.png)
> **Python3**
> ![image.png](https://assets.leetcode.com/users/images/34e5704e-2b5f-48b2-9038-c6bd0a150002_1729828166.235278.png)
> [💡 | O(n log n + n * m) | C++ 29ms Beats 100.00% | Py3 19 ms Beats 98.28% | Java 42ms |](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25)

> ### Additional Note
> This solution leverages sorting to manage sub-folder hierarchy efficiently. Sorting helps line up potential sub-folders after their parent folders, enabling quick comparison and skipping with minimal overhead.

---

