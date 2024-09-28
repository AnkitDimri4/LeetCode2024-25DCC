#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
    vector<int> d; 
    int f, r, sz, cap;
public:
    MyCircularDeque(int k) : d(k), f(0), r(0), sz(0), cap(k) {}
    
    bool insertFront(int v) { 
        if (isFull()) return false; 
        f = (f - 1 + cap) % cap; 
        d[f] = v; 
        sz++; 
        return true; 
    }
    
    bool insertLast(int v) { 
        if (isFull()) return false; 
        d[r] = v; 
        r = (r + 1) % cap; 
        sz++; 
        return true; 
    }
    
    bool deleteFront() { 
        if (isEmpty()) return false; 
        f = (f + 1) % cap; 
        sz--; 
        return true; 
    }
    
    bool deleteLast() { 
        if (isEmpty()) return false; 
        r = (r - 1 + cap) % cap; 
        sz--; 
        return true; 
    }
    
    int getFront() { 
        return isEmpty() ? -1 : d[f]; 
    }
    
    int getRear() { 
        return isEmpty() ? -1 : d[(r - 1 + cap) % cap]; 
    }
    
    bool isEmpty() { 
        return sz == 0; 
    }
    
    bool isFull() { 
        return sz == cap; 
    }
};

int main() {
    MyCircularDeque deque(3);  // Create a deque of capacity 3

    cout << deque.insertLast(1) << "\n";  // Insert 1 at the rear. Return true
    cout << deque.insertLast(2) << "\n";  // Insert 2 at the rear. Return true
    cout << deque.insertFront(3) << "\n";  // Insert 3 at the front. Return true
    cout << deque.insertFront(4) << "\n";  // Insert 4 at the front. Return false (Deque is full)
    cout << deque.getRear() << "\n";      // Get the rear element. Return 2
    cout << deque.isFull() << "\n";       // Check if deque is full. Return true
    cout << deque.deleteLast() << "\n";   // Delete the rear element. Return true
    cout << deque.insertFront(4) << "\n";  // Insert 4 at the front. Return true
    cout << deque.getFront() << "\n";     // Get the front element. Return 4

    return 0;
}
