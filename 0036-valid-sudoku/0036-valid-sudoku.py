class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        mask = 0
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == '.':
                    continue
                if mask & (1 << int(board[i][j])):
                    return False
                else:
                    mask |= (1 << int(board[i][j]))
            mask = 0
        for i in range(len(board)):
            for j in range(len(board)):
                if board[j][i] == '.':
                    continue
                if mask & (1 << int(board[j][i])):
                    return False
                else:
                    mask |= (1 << int(board[j][i]))
            mask = 0
        for i in range(0, len(board), 3):
            for j in range(0, len(board), 3):
                for k in range(i, i + 3):
                    for l in range(j, j + 3):
                        if board[k][l] == '.':
                            continue
                        if mask & (1 << int(board[k][l])):
                            return False
                        else:
                            mask |= (1 << int(board[k][l]))
                mask = 0
        return True
        