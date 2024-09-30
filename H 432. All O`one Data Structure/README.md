#
---
> # Intuition
To manage string counts efficiently, we implement an **AllOne** data structure that allows for **incrementing** and **decrementing** string counts while also providing the ability to retrieve keys with the **maximum** and **minimum** counts in constant time.

> # Approach
We utilize a **hash map** to store string counts and a **frequency map** to link counts to their respective strings. Each string's count is incremented or decremented as needed, while the frequency map make sures we can easily access keys with the current minimum and maximum counts.

> # Complexity
- **Time Complexity** The average time complexity for all operations ($$inc$$, $$dec$$, $$getMaxKey$$, $$getMinKey$$) is $$O(1)$$ in practice due to the efficient use of hash maps. However, note that operations on $$std::map$$ do have a complexity of $$O(log n)$$. The use of $$max(self.freq)$$ and $$min(self.freq)$$ can run in $$O(n)$$, so maintaining pointers for max/min would allow all operations to consistently remain **O(1)**. Thus, the combined use of hash maps provides effective performance.
- **Space Complexity** $$O(n)$$, where $$n$$ is the number of unique strings stored.

---
# Code
```cpp []
class AllOne {
    unordered_map<string, int> count;
    map<int, unordered_set<string>> freq;
public:
    AllOne() {}
    void inc(string key) {
        int cnt = count[key]++;
        if (cnt > 0) freq[cnt].erase(key);
        freq[cnt + 1].insert(key);
        if (freq[cnt].empty()) freq.erase(cnt);
    }
    void dec(string key) {
        int cnt = count[key]--;
        if (cnt > 0) freq[cnt].erase(key);
        if (cnt == 1) count.erase(key);
        else freq[cnt - 1].insert(key);
        if (freq[cnt].empty()) freq.erase(cnt);
    }
    string getMaxKey() {
        return freq.empty() ? "" : *(freq.rbegin()->second.begin());
    }
    string getMinKey() {
        return freq.empty() ? "" : *(freq.begin()->second.begin());
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
```
```Java []
class Node {
    int cnt;
    Set<String> keys;
    Node prev, next; 
    public Node(int c) {
        cnt = c;
        keys = new HashSet<>();
        prev = next = null;
    }
}
class AllOne {
    private Map<String, Integer> keyCnt; 
    private Map<Integer, Node> cntNodeMap; 
    private Node head, tail;
    public AllOne() {
        keyCnt = new HashMap<>();
        cntNodeMap = new HashMap<>();
        head = new Node(Integer.MIN_VALUE);
        tail = new Node(Integer.MAX_VALUE);
        head.next = tail;
        tail.prev = head;
    }
    private Node addNodeAfter(Node node, int c) {
        Node newNode = new Node(c);
        newNode.next = node.next;
        newNode.prev = node;
        node.next.prev = newNode;
        node.next = newNode;
        cntNodeMap.put(c, newNode);
        return newNode;
    }
    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        cntNodeMap.remove(node.cnt);
    }
    public void inc(String key) {
        int c = keyCnt.getOrDefault(key, 0);
        keyCnt.put(key, c + 1);
        Node curr = cntNodeMap.get(c);
        Node next = cntNodeMap.get(c + 1);
        if (next == null) next = addNodeAfter(curr == null ? head : curr, c + 1);
        next.keys.add(key);
        if (curr != null) {
            curr.keys.remove(key);
            if (curr.keys.isEmpty()) removeNode(curr);
        }
    }
    public void dec(String key) {
        int c = keyCnt.get(key);
        if (c == 1) keyCnt.remove(key);
        else keyCnt.put(key, c - 1);

        Node curr = cntNodeMap.get(c);
        Node prev = cntNodeMap.get(c - 1);

        if (c > 1 && prev == null) prev = addNodeAfter(curr.prev, c - 1);
        if (c > 1) prev.keys.add(key);

        curr.keys.remove(key);
        if (curr.keys.isEmpty()) removeNode(curr);
    }
    public String getMaxKey() {
        return tail.prev == head ? "" : tail.prev.keys.iterator().next();
    }
    public String getMinKey() {
        return head.next == tail ? "" : head.next.keys.iterator().next();
    }
}
```
```python3 []
class AllOne:
    def __init__(self):
        self.count = defaultdict(int)
        self.freq = defaultdict(set)
    def inc(self, key: str) -> None:
        cnt = self.count[key]
        if cnt > 0:
            self.freq[cnt].remove(key)
        self.count[key] += 1
        self.freq[cnt + 1].add(key)
        if not self.freq[cnt]:
            del self.freq[cnt]
    def dec(self, key: str) -> None:
        cnt = self.count[key]
        self.freq[cnt].remove(key)
        if cnt == 1:
            del self.count[key]
        else:
            self.count[key] -= 1
            self.freq[cnt - 1].add(key)
        if not self.freq[cnt]:
            del self.freq[cnt]
    def getMaxKey(self) -> str:
        return next(iter(self.freq[max(self.freq)]), "") if self.freq else ""
    def getMinKey(self) -> str:
        return next(iter(self.freq[min(self.freq)]), "") if self.freq else ""
```
---
> ![image.png](https://assets.leetcode.com/users/images/0dd81f48-084b-470b-9032-53ce13f75da0_1727577170.9954724.png)
> [O(1) | Easy Solution | C++ 72ms Beats 96.88% | Java Python3](https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29)

---
> ### Additional Note
> **Note**: While the theoretical complexity provides a framework for understanding performance, real-world implications can vary based on implementation details. The practical performance for managing frequencies can often approach **O(√n)**, which should be considered in dynamic scenarios.

---
