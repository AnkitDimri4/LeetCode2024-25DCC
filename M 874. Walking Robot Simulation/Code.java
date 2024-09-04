import java.util.HashSet;
import java.util.Set;

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

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] cmds = {4, -1, 3};
        int[][] obs = {{2, 4}};
        System.out.println(sol.robotSim(cmds, obs)); // Output: 25
    }
}
