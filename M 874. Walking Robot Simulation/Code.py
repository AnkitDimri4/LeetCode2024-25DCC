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
sol = Solution()
cmds = [4, -1, 3]
obs = [[2, 4]]
print(sol.robotSim(cmds, obs))  # Output: 25
