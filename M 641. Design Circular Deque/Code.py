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

deque = MyCircularDeque(3)  # Create a deque of capacity 3
print(deque.insertLast(1))  # Insert 1 at the rear. Return True
print(deque.insertLast(2))  # Insert 2 at the rear. Return True
print(deque.insertFront(3)) # Insert 3 at the front. Return True
print(deque.insertFront(4)) # Insert 4 at the front. Return False (Deque is full)
print(deque.getRear())      # Get the rear element. Return 2
print(deque.isFull())       # Check if deque is full. Return True
print(deque.deleteLast())   # Delete the rear element. Return True
print(deque.insertFront(4)) # Insert 4 at the front. Return True
print(deque.getFront())     # Get the front element. Return 4
