class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned short mask = 0;
        for (char i = 0; i < board.size(); i++) {
            for (char j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    if (mask & (1 << (board[i][j] - '0'))) {
                        return false;
                    }
                    mask |= (1 << (board[i][j] - '0'));
                }
            }
            mask = 0;
        }
        for (char i = 0; i < board.size(); i++) {
            for (char j = 0; j < board.size(); j++) {
                if (board[j][i] != '.') {
                    if (mask & (1 << (board[j][i] - '0'))) {
                        return false;
                    }
                    mask |= (1 << (board[j][i] - '0'));
                }
            }
            mask = 0;
        }
        for (char i = 0; i < board.size(); i += 3) {
            for (char j = 0; j < board.size(); j += 3) {
                for (char k = i; k < i + 3; k++) {
                    for (char l = j; l < j + 3; l++) {
                        if (board[k][l] != '.') {
                            if (mask & (1 << (board[k][l] - '0'))) {
                                return false;
                            }
                            mask |= (1 << (board[k][l] - '0'));
                        }
                    }
                }
                mask = 0;
            }
        }
        return true;
    }
};