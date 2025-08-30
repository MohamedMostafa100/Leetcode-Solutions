class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> search(10, vector<vector<bool>>(3, vector<bool>(9, false)));
        
        for(char i = 0; i < board.size(); i++)
        {
            for(char j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    if(search[board[i][j] - 48][0][i])
                    {
                        return false;
                    }
                    else
                    {
                        search[board[i][j] - 48][0][i] = true;
                    }

                    if(search[board[i][j] - 48][1][j])
                    {
                        return false;
                    }
                    else
                    {
                        search[board[i][j] - 48][1][j] = true;
                    }

                    char rowNum = (i - (i % 3)) / 3;
                    char colNum = (j - (j % 3)) / 3;
                    char blockNum = rowNum * 3 + colNum;

                    if(search[board[i][j] - 48][2][blockNum])
                    {
                        return false;
                    }
                    else
                    {
                        search[board[i][j] - 48][2][blockNum] = true;
                    }
                }
            }
        }

        return true;
    }
};