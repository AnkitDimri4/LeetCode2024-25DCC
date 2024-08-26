class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def postorder(self, root: Node) -> list[int]:
        res = []
        self.traverse(root, res)
        return res

    def traverse(self, node: Node, res: list[int]):
        if node is None:
            return
        for child in node.children:
            self.traverse(child, res)
        res.append(node.val)

if __name__ == "__main__":
    root = Node(1, [
        Node(3, [Node(5), Node(6)]),
        Node(2),
        Node(4)
    ])

    sol = Solution()
    result = sol.postorder(root)
    print(result)  # Output: [5, 6, 3, 2, 4, 1]
