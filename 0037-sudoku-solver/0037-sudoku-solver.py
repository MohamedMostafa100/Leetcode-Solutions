class Solution:
    def solve(self, board: List[List[str]], search: List[List[List[str]]], i: int, j: int) -> bool:
        if i == 9:
            return True
        if board[i][j] != '.':
            if self.solve(board, search, i + (j // 8), (j + 1) % 9):
                return True
        else:
            rowNum = (i - (i % 3)) // 3
            colNum = (j - (j % 3)) // 3
            blockNum = rowNum * 3 + colNum
            for k in range(1, 10):
                if not search[k][0][i] and not search[k][1][j] and not search[k][2][blockNum]:
                    board[i][j] = f"{k}"
                    search[k][0][i] = True
                    search[k][1][j] = True
                    search[k][2][blockNum] = True
                    if self.solve(board, search, i + (j // 8), (j + 1) % 9):
                        return True
                    board[i][j] = '.'
                    search[k][0][i] = False
                    search[k][1][j] = False
                    search[k][2][blockNum] = False
        return False


 
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        search = [[[False for i in range(9)] for j in range(3)] for k in range(10)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    rowNum = (i - (i % 3)) // 3
                    colNum = (j - (j % 3)) // 3
                    blockNum = rowNum * 3 + colNum
                    search[int(board[i][j])][0][i] = True
                    search[int(board[i][j])][1][j] = True
                    search[int(board[i][j])][2][blockNum] = True
        self.solve(board, search, 0, 0)
        