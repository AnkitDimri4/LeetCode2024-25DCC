import java.util.Arrays;

class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        long total = 0, chem = 0;
        for (int x : skill) total += x;
        total /= (skill.length / 2);
        int i = 0, j = skill.length - 1;
        while (i < j) {
            if (skill[i] + skill[j] != total) return -1;
            chem += (long) skill[i] * skill[j];
            i++;
            j--;
        }
        return chem;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] skills = {1, 3, 2, 4};
        long result = sol.dividePlayers(skills);
        System.out.println("Output: " + result); // Expected Output: 10
    }
}
