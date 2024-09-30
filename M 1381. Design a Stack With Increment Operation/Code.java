import java.util.ArrayList;

class CustomStack {
    private ArrayList<Integer> stack;
    private int[] inc;
    private int maxSize;

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        stack = new ArrayList<>();
        inc = new int[maxSize];
    }

    public void push(int x) {
        if (stack.size() < maxSize) {
            stack.add(x);
            inc[stack.size() - 1] = 0;
        }
    }

    public int pop() {
        if (stack.isEmpty()) return -1;
        int idx = stack.size() - 1;
        int res = stack.get(idx) + inc[idx];
        stack.remove(idx);
        if (idx > 0) inc[idx - 1] += inc[idx];
        return res;
    }

    public void increment(int k, int val) {
        if (!stack.isEmpty()) {
            int idx = Math.min(k, stack.size()) - 1;
            inc[idx] += val;
        }
    }

    public static void main(String[] args) {
        CustomStack customStack = new CustomStack(3);
        customStack.push(1);
        customStack.push(2);
        System.out.println(customStack.pop()); // Output: 2
        customStack.push(2);
        customStack.push(3);
        customStack.push(4); // Stack is full
        System.out.println(customStack.pop()); // Output: 3
        customStack.increment(5, 100); // Increment first 5 elements by 100
        System.out.println(customStack.pop()); // Output: 102
        System.out.println(customStack.pop()); // Output: 101
        System.out.println(customStack.pop()); // Output: -1 (stack is empty)
    }
}
