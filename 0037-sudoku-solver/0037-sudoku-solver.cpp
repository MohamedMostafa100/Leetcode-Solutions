class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> search(10, vector<vector<bool>>(3, vector<bool>(9, false)));
        for(char i = 0; i < board.size(); i++)
        {
            for(char j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    search[board[i][j] - '0'][0][i] = true;
                    search[board[i][j] - '0'][1][j] = true;
                    char rowNum = (i - (i % 3)) / 3;
                    char colNum = (j - (j % 3)) / 3;
                    char blockNum = rowNum * 3 + colNum;
                    search[board[i][j] - '0'][2][blockNum] = true;
                }
            }
        }
        solve(board, search, 0, 0);
    }
private:
    bool solve(vector<vector<char>>& board, vector<vector<vector<bool>>>& search, char i, char j)
    {
        if(i == 9)
        {
            return true;
        }
        if(board[i][j] != '.')
        {
            if(solve(board, search, i + (j / 8), (j + 1) % 9))
            {
                return true;
            }
        }
        else
        {
            char rowNum = (i - (i % 3)) / 3;
            char colNum = (j - (j % 3)) / 3;
            char blockNum = rowNum * 3 + colNum;
            for(char k = 1; k <= 9; k++)
            {
                if(!search[k][0][i] && !search[k][1][j] && !search[k][2][blockNum])
                {
                    board[i][j] = '0' + k;
                    search[k][0][i] = true;
                    search[k][1][j] = true;
                    search[k][2][blockNum] = true;
                    if(solve(board, search, i + (j / 8), (j + 1) % 9))
                    {
                        return true;
                    }
                    board[i][j] = '.';
                    search[k][0][i] = false;
                    search[k][1][j] = false;
                    search[k][2][blockNum] = false;
                }
            }
        }
        return false;
    }
};