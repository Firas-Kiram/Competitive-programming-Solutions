# problem : 1483. Kth Ancestor of a Tree Node - https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.LOG = 21
        self.n = n
        self.anc = [[-1 for _ in range(self.LOG)] for _ in range(n)]  

        for i in range(n):
            self.anc[i][0] = parent[i]

        for j in range(1, self.LOG):
            for i in range(n):
                if self.anc[i][j - 1] != -1:
                    self.anc[i][j] = self.anc[self.anc[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(self.LOG):
            if (k >> i) & 1:
                node = self.anc[node][i]
            if node == -1: break
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n , parent)
# param_1 = obj.getKthAncestor(node,k)
