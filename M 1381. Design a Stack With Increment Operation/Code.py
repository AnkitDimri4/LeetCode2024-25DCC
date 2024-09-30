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


if __name__ == "__main__":
    customStack = CustomStack(3)
    customStack.push(1)
    customStack.push(2)
    print(customStack.pop())  # Output: 2
    customStack.push(2)
    customStack.push(3)
    customStack.push(4)  # Stack is full
    print(customStack.pop())  # Output: 3
    customStack.increment(5, 100)  # Increment first 5 elements by 100
    print(customStack.pop())  # Output: 102
    print(customStack.pop())  # Output: 101
    print(customStack.pop())  # Output: -1 (stack is empty)
