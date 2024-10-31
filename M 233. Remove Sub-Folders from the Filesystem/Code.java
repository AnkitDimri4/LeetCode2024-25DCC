import java.util.*;

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
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] folder1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
        System.out.println(solution.removeSubfolders(folder1)); // Output: ["/a", "/c/d", "/c/f"]
        String[] folder2 = {"/a", "/a/b/c", "/a/b/d"};
        System.out.println(solution.removeSubfolders(folder2)); // Output: ["/a"]
    }
}
