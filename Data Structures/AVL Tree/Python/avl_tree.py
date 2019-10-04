class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class AVLTree():
    def __init__(self, nodes=list()):
        self.node = None
        self.height = -1
        self.balance = 0

        for node in nodes:
            self.insert(node)

    def height(self):
        return getattr(self.node, "height", 0)

    def is_leaf(self):
        return self.height == 0

    def insert(self, key):
        tree = self.node

        if tree is None:
            self.node = Node(key)
            self.node.left = AVLTree()
            self.node.right = AVLTree()

        elif key < tree.key:
            self.node.left.insert(key)

        elif key > tree.key:
            self.node.right.insert(key)

        self.rebalance()

    def rebalance(self):
        self.update(recursive=False)

        while self.balance < -1 or self.balance > 1:
            if self.balance > 1:
                if self.node.left.balance < 0:
                    self.node.node.rotate("left")
                    self.update()

                self.rotate("right")
                self.update()

            if self.balance < -1:
                if self.node.right.balance > 0:
                    self.node.right.rotate("right")
                    self.update()

                self.rotate("left")
                self.update()

    def rotate(self, direction):
        assert direction in ["right", "left"], f"Expected right or left"

        opposite_direction = "right" if direction == "left" else "left"
        node_a = self.node
        node_b = getattr(self.node, opposite_direction).node
        node_t = getattr(node_b, direction).node

        self.node = node_b
        getattr(node_b, direction).node = node_a
        getattr(node_a, opposite_direction).node = node_t

    def updater(self, mode, recursive=True):
        assert mode in ["height", "balance"], "Expected height or balance"

        if self.node is not None:
            if recursive:
                if self.node.left is not None:
                    self.node.left.updater(mode)

                if self.node.right is not None:
                    self.node.right.updater(mode)

            if mode == "height":
                max_height = max(self.node.left.height, self.node.right.height)
                self.height = max_height + 1

            elif mode == "balance":
                self.balance = self.node.left.height - self.node.right.height

        elif mode == "height":
            self.height = -1

        elif mode == "balance":
            self.balance = 0

    def update(self, recursive=True):
        self.updater("height")
        self.updater("balance")

    def delete(self, key):
        if self.node is not None:
            if self.node.key == key:
                if self.node.left.node is None and self.node.right.node is None:
                    self.node = None

                elif self.node.left is None:
                    self.node = self.node.right.node

                elif self.node.right is None:
                    self.node = self.node.left.node

                else:
                    replacement = self.pick("successor", self.node)
                    if replacement is not None:
                        self.node.key = replacement.key
                        self.node.right.delete(replacement.key)

            elif key < self.node.key:
                self.node.left.delete(key)

            elif key > self.node.key:
                self.node.right.delete(key)

            self.rebalance()

    def pick(self, mode, node):
        expected = "Expected predecessor or successor"
        assert mode in ["predecessor", "successor"], expected

        direction = "right" if mode == "predecessor" else "left"
        opposite_direction = "right" if direction == "left" else "left"

        node = getattr(node, opposite_direction).node
        if node is not None:
            while getattr(node, direction) is not None:
                if getattr(node, direction).node is None:
                    return node

                node = getattr(node, direction).node

        return node

    def balance_check(self):
        if self is None or self.node is None:
            return True

        self.update()
        return all([
            abs(self.balance) < 2,
            self.node.left.balance_check(),
            self.node.right.balance_check()
        ])

    def traverse(self):
        if self.node is None:
            return list()

        traversal = list()
        left_traverse = self.node.left.traverse()
        right_traverse = self.node.right.traverse()

        traversal.extend(left_traverse)
        traversal.append(self.node.key)
        traversal.extend(right_traverse)

        return traversal

    def view(self, depth=0, direction=None):
        self.update()
        if self.node is not None:
            prefix = "\t" * depth
            key = self.node.key
            height = self.height
            balance = self.balance
            leaf = "leaf" if self.is_leaf() else ""

            if direction is not None:
                direction = f" {direction} "
            else:
                direction = ""

            print(f"{prefix}{direction}{key} [{height}:{balance}] {leaf}")

            if self.node.left is not None:
                self.node.left.view(depth + 1, "<")

            if self.node.right is not None:
                self.node.right.view(depth + 1, ">")

if __name__ == "__main__":
    tree = AVLTree()
    seed = [3, 1, 4, 1, 5, 9, 2, 6, 5]
    for s in seed:
        tree.insert(s)

    print("Initial tree")
    tree.view()

    tree.delete(1)
    tree.delete(2)
    tree.delete(3)

    print("Trimmed tree")
    tree.view()

    print(f"Traversal: {tree.traverse()}")
