import java.util.ArrayList;
import java.util.List;

class Solution {
    int idx = 0;
    
    public boolean parseBoolExpr(String e) {
        char op = e.charAt(idx++);
        if (op == 't') return true; 
        if (op == 'f') return false; 
        idx++; 
        List<Boolean> vals = new ArrayList<>();
        while (e.charAt(idx) != ')') {
            if (e.charAt(idx) != ',') vals.add(parseBoolExpr(e)); 
            else idx++; 
        }
        idx++;
        return op == '!' ? !vals.get(0) : op == '&' ? vals.stream().allMatch(v -> v) : vals.stream().anyMatch(v -> v);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.parseBoolExpr("&(t,t,t)"));  // Output: true
        System.out.println(solution.parseBoolExpr("&(|(f))"));    // Output: false
        System.out.println(solution.parseBoolExpr("|(f,f,f,t)")); // Output: true
        System.out.println(solution.parseBoolExpr("!(&(f,t))"));  // Output: true
    }
}
