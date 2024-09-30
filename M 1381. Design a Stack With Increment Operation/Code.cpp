#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main() {
    CustomStack customStack(3);
    customStack.push(1);
    customStack.push(2);
    cout << customStack.pop() << "\n"; // Output: 2
    customStack.push(2);
    customStack.push(3);
    customStack.push(4); // Stack is full
    cout << customStack.pop() << "\n"; // Output: 3
    customStack.increment(5, 100); // Increment first 5 elements by 100
    cout << customStack.pop() << "\n"; // Output: 102
    cout << customStack.pop() << "\n"; // Output: 101
    cout << customStack.pop() << "\n"; // Output: -1 (stack is empty)
    return 0;
}
