# 
---
> # Intuition
Designing a **Circular Deque** can be efficiently done by using a fixed-size array with front and rear pointers that wrap around the array using modulo operations. This structure allows constant time operations for insertion and deletion from both ends. The key is to manage the size of the deque correctly and handle the wrapping of indices when the array is full or empty.

> # Approach
We maintain an array of fixed size **k** and use two pointers **f** and **r** to track the front and rear ends of the deque. Insertions and deletions are done by adjusting these pointers circularly using modulo arithmetic. For operations such as **insertFront** and **insertLast**, we move the respective pointers and place elements in the deque. Similarly, for **deleteFront** and **deleteLast**, we adjust the pointers to effectively remove elements. Special care is taken to check if the deque is full or empty to prevent overflows.

> # Complexity
- **Time Complexity** $$O(1)$$ for all operations because insertion, deletion, and access operations are performed using direct index manipulation.
- **Space Complexity** $$O(k)$$ where $$k$$ is the capacity of the deque, used to store the elements in the array.

> # Code
```cpp []
class MyCircularDeque {
    vector<int> d; int f, r, sz, cap;
public:
    MyCircularDeque(int k) : d(k), f(0), r(0), sz(0), cap(k) {}
    inline bool insertFront(int v) { if (isFull()) return false; f = (f - 1 + cap) % cap; d[f] = v; sz++; return true; }
    inline bool insertLast(int v) { if (isFull()) return false; d[r] = v; r = (r + 1) % cap; sz++; return true; }
    inline bool deleteFront() { if (isEmpty()) return false; f = (f + 1) % cap; sz--; return true; }
    inline bool deleteLast() { if (isEmpty()) return false; r = (r - 1 + cap) % cap; sz--; return true; }
    inline int getFront() { return isEmpty() ? -1 : d[f]; }
    inline int getRear() { return isEmpty() ? -1 : d[(r - 1 + cap) % cap]; }
    inline bool isEmpty() { return !sz; }
    inline bool isFull() { return sz == cap; }
};
```

```java []
class MyCircularDeque {
    private int[] d;
    private int f, r, sz, cap;
    public MyCircularDeque(int k) { d = new int[k]; f = 0; r = 0; sz = 0; cap = k; }
    public boolean insertFront(int v) { if (isFull()) return false; f = (f - 1 + cap) % cap; d[f] = v; sz++; return true; }
    public boolean insertLast(int v) { if (isFull()) return false; d[r] = v; r = (r + 1) % cap; sz++; return true; }
    public boolean deleteFront() { if (isEmpty()) return false; f = (f + 1) % cap; sz--; return true; }
    public boolean deleteLast() { if (isEmpty()) return false; r = (r - 1 + cap) % cap; sz--; return true; }
    public int getFront() { return isEmpty() ? -1 : d[f]; }
    public int getRear() { return isEmpty() ? -1 : d[(r - 1 + cap) % cap]; }
    public boolean isEmpty() { return sz == 0; }
    public boolean isFull() { return sz == cap; }
}
```

```python []
class MyCircularDeque:
    def __init__(self, k: int):
        self.d = [0] * k
        self.f = 0
        self.r = 0
        self.sz = 0
        self.cap = k
    def insertFront(self, v: int) -> bool:
        if self.isFull(): return False
        self.f = (self.f - 1 + self.cap) % self.cap
        self.d[self.f] = v
        self.sz += 1
        return True
    def insertLast(self, v: int) -> bool:
        if self.isFull(): return False
        self.d[self.r] = v
        self.r = (self.r + 1) % self.cap
        self.sz += 1
        return True
    def deleteFront(self) -> bool:
        if self.isEmpty(): return False
        self.f = (self.f + 1) % self.cap
        self.sz -= 1
        return True
    def deleteLast(self) -> bool:
        if self.isEmpty(): return False
        self.r = (self.r - 1 + self.cap) % self.cap
        self.sz -= 1
        return True
    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.d[self.f]
    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.d[(self.r - 1 + self.cap) % self.cap]
    def isEmpty(self) -> bool:
        return self.sz == 0
    def isFull(self) -> bool:
        return self.sz == self.cap
```

---
> C++
- ![image.png](https://assets.leetcode.com/users/images/c95a1b33-9fa6-45c7-9693-e64f60836482_1727493832.6680007.png)
> Java 
- ![image.png](https://assets.leetcode.com/users/images/039782da-e9d5-406b-affc-25cd883d5c43_1727493919.4203892.png)
- [💡 O(1) | C++ 7ms Beats 99.76% | Java 4ms Beats 100% | Python3](https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28)

---