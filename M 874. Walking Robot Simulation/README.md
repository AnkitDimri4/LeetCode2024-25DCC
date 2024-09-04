🌟
#
---

# Intuition
The robot is navigating an infinite 2D grid and can turn left, turn right, or move forward. The key challenge is handling obstacles that may block the robot movement. To solve this, we simulate the robot movement by updating its coordinates based on its current direction and checking for obstacles before each step. Using a set to store obstacles allows for efficient lookup, making sure that the robot stops when encountering an obstacle and continues otherwise. The goal is to track the maximum distance squared from the origin during the robot journey.

# Approach
We use a direction array to manage the robot movement in the four cardinal directions (north, east, south, and west). As we process each command, we update the robot direction or move it forward step by step, checking for obstacles. If the robot encounters an obstacle, it halts and proceeds to the next command. Throughout the simulation, we track the maximum Euclidean distance squared from the origin.

# Complexity
- **Time complexity** $$O(n+m)$$ where $$𝑛$$ is the number of commands and $$𝑚$$ is the number of obstacles. The set operations (insert, lookup) are efficient, allowing us to quickly handle obstacles.

- **Space complexity** $$𝑂(𝑚)$$ for storing the obstacles in a set.


# Code
```cpp []
class Solution {
public:
    int robotSim(vector<int>& cmds, vector<vector<int>>& obs) {
        unordered_set<long> obsSet;
        for (auto& o : obs) obsSet.insert(static_cast<long>(o[0]) * 100000 + o[1]);
        vector<int> dirs = {0, 1, 0, -1}; 
        int x{0}, y{0}, d{0}, maxDist{0};
        for (int cmd : cmds) {
            if (cmd == -1) d = (d + 1) % 4; 
            else if (cmd == -2) d = (d + 3) % 4; 
            else {
                while (cmd--) {
                    int nx = x + dirs[d], ny = y + dirs[d ^ 1];
                    if (!obsSet.count(static_cast<long>(nx) * 100000 + ny)) {
                        x = nx; y = ny;
                        maxDist = max(maxDist, x * x + y * y);
                    } else break;
                }
            }
        }
        return maxDist;
    }
};

```
```java []
class Solution {
    public int robotSim(int[] cmds, int[][] obs) {
        Set<Long> obsSet = new HashSet<>();
        for (int[] o : obs) obsSet.add((long) o[0] * 100000 + o[1]);
        int[] dirs = {0, 1, 0, -1};
        int x = 0, y = 0, d = 0, maxDist = 0;
        for (int cmd : cmds) {
            if (cmd == -1) d = (d + 1) % 4;
            else if (cmd == -2) d = (d + 3) % 4;
            else {
                while (cmd-- > 0) {
                    int nx = x + dirs[d], ny = y + dirs[d ^ 1];
                    if (!obsSet.contains((long) nx * 100000 + ny)) {
                        x = nx; y = ny;
                        maxDist = Math.max(maxDist, x * x + y * y);
                    } else break;
                }
            }
        }
        return maxDist;
    }
}

```

```python []
class Solution:
    def robotSim(self, cmds: List[int], obs: List[List[int]]) -> int:
        obsSet = {tuple(o) for o in obs}
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        x = y = d = maxDist = 0
        for cmd in cmds:
            if cmd == -1:
                d = (d + 1) % 4
            elif cmd == -2:
                d = (d + 3) % 4
            else:
                for _ in range(cmd):
                    nx, ny = x + dirs[d][0], y + dirs[d][1]
                    if (nx, ny) not in obsSet:
                        x, y = nx, ny
                        maxDist = max(maxDist, x * x + y * y)
                    else:
                        break
        return maxDist
```

---

- ![image.png](https://assets.leetcode.com/users/images/a3d6f4bc-f26a-4b95-8988-aa2c277d44bd_1725419996.080206.png)

- [| 49ms Beats 97.51%| O (n + m) | Efficient Solution | C++ | Python | Java](https://leetcode.com/problems/walking-robot-simulation/description/)
---