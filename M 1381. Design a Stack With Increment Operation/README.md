#
---
> # Intuition
To design a stack that supports efficient increment operations on its elements, we utilize two data structures: one to store the stack elements and another to track increment values for each element. This allows us to manage both the push and pop operations while maintaining the ability to increment the bottom k elements efficiently.

> # Approach
We implement a **CustomStack** class with methods to push elements onto the stack, pop elements off the stack, and increment the bottom k elements by a given value. The increment operations are performed by using an auxiliary array that holds pending increments, which are applied during the pop operation to ensure efficiency.

> # Complexity
- **Time Complexity** Each operation (push, pop, increment) runs in $$O(1)$$ time on average.
- **Space Complexity** The space used is $$O(n)$$ for storing the elements and increment values, where n is the maximum size of the stack.
---
> # Code
```cpp []
class CustomStack {
    vector<int> stack, inc;
    int maxSize;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        stack.reserve(maxSize);
        inc.resize(maxSize, 0);  
    }
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc[stack.size() - 1] = 0;  
        }
    }
    int pop() {
        if (stack.empty()) return -1;
        int idx = stack.size() - 1;
        int res = stack[idx] + inc[idx];
        stack.pop_back();
        if (idx > 0) inc[idx - 1] += inc[idx];
        return res;
    }
    void increment(int k, int val) {
        if (!stack.empty()) {
            int idx = min(k, (int)stack.size()) - 1;
            inc[idx] += val; 
        }
    }
};
```
```java []
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
}
```
```python []
class CustomStack:
    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.stack = []
        self.inc = [0] * maxSize
    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)
            self.inc[len(self.stack) - 1] = 0
    def pop(self) -> int:
        if not self.stack:
            return -1
        idx = len(self.stack) - 1
        res = self.stack[idx] + self.inc[idx]
        self.stack.pop()
        if idx > 0:
            self.inc[idx - 1] += self.inc[idx]
        return res
    def increment(self, k: int, val: int) -> None:
        if self.stack:
            idx = min(k, len(self.stack)) - 1
            self.inc[idx] += val
```

---
> ![image.png](https://assets.leetcode.com/users/images/a1389d72-c245-491c-92f4-1c33ab6b0b48_1727668901.9191017.png)
> ![💡O(1) (Average) | Easy Solution | C++ 15ms Beats 99.30% | Java Python3](https://leetcode.com/problems/design-a-stack-with-increment-operation/description/?envType=daily-question&envId=2024-09-30)
---


> ### Additional Note
> **Note**: While the theoretical complexity provides a framework for understanding performance, real-world implications can vary based on implementation details. The practical performance for managing the stack can often approach $$O(1)$$, which should be considered in dynamic scenarios.

---