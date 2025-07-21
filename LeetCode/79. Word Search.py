# problem : Word Search - https://leetcode.com/problems/word-search/
class Solution:

    def dfs(self , i : int , j : int , s : str , idx : int) -> bool:
        if i >= self.n or j >= self.m or j < 0 or i < 0 or self.vis[i][j] == True or self.word[idx] != self.board[i][j]:
            return False
        self.vis[i][j] = True
        s += self.board[i][j]
        if s == self.word : return True
        if self.dfs(i + 1 , j , s , idx + 1) : return True
        if self.dfs(i , j + 1 , s , idx + 1) : return True
        if self.dfs(i - 1 , j , s , idx + 1) : return True
        if self.dfs(i , j - 1 , s , idx + 1) : return True
        self.vis[i][j] = False
        return False


    def exist(self, board: List[List[str]], word: str) -> bool:
        self.n = len(board)
        self.m = len(board[0])
        self.board = board
        self.word = word
        ret = False
        for i in range(self.n):
            for j in range(self.m):
                self.vis = [[False for _ in range(self.m)] for _ in range(self.n)]
                s = ""
                ret = ret or self.dfs(i , j , s , 0)

        return ret
