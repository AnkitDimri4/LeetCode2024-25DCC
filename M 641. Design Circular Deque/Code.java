public class MyCircularDeque {
    private int[] d;
    private int f, r, sz, cap;

    public MyCircularDeque(int k) {
        d = new int[k];
        f = 0;
        r = 0;
        sz = 0;
        cap = k;
    }

    public boolean insertFront(int v) {
        if (isFull()) return false;
        f = (f - 1 + cap) % cap;
        d[f] = v;
        sz++;
        return true;
    }

    public boolean insertLast(int v) {
        if (isFull()) return false;
        d[r] = v;
        r = (r + 1) % cap;
        sz++;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) return false;
        f = (f + 1) % cap;
        sz--;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) return false;
        r = (r - 1 + cap) % cap;
        sz--;
        return true;
    }

    public int getFront() {
        return isEmpty() ? -1 : d[f];
    }

    public int getRear() {
        return isEmpty() ? -1 : d[(r - 1 + cap) % cap];
    }

    public boolean isEmpty() {
        return sz == 0;
    }

    public boolean isFull() {
        return sz == cap;
    }

    public static void main(String[] args) {
        MyCircularDeque deque = new MyCircularDeque(3);  // Create a deque of capacity 3

        System.out.println(deque.insertLast(1));  // Insert 1 at the rear. Return true
        System.out.println(deque.insertLast(2));  // Insert 2 at the rear. Return true
        System.out.println(deque.insertFront(3)); // Insert 3 at the front. Return true
        System.out.println(deque.insertFront(4)); // Insert 4 at the front. Return false (Deque is full)
        System.out.println(deque.getRear());      // Get the rear element. Return 2
        System.out.println(deque.isFull());       // Check if deque is full. Return true
        System.out.println(deque.deleteLast());   // Delete the rear element. Return true
        System.out.println(deque.insertFront(4)); // Insert 4 at the front. Return true
        System.out.println(deque.getFront());     // Get the front element. Return 4
    }
}
