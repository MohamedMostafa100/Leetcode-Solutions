class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        char n = grid.size();
        char m = grid[0].size();
        for(char i = 0; i < n - 2; i++)
        {
            for(char j = 0; j < m - 2; j++)
            {
                if(checkMagic(grid, i, j))
                {
                    res++;
                }
            }
        }
        return res;
    }
private:
    bool checkMagic(vector<vector<int>>& grid, char i, char j)
    {
        bool arr[9] = {false};
        char checkSum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        for(char row = i; row < i + 3; row++)
        {
            for(char col = j; col < j + 3; col++)
            {
                if(grid[row][col] == 0 || grid[row][col] > 9 || arr[grid[row][col] - 1])
                {
                    return false;
                }
                arr[grid[row][col] - 1] = true;
            }
        }
        char row2 =  grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        char row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        if(row2 != checkSum || row3 != checkSum)
        {
            return false;
        }
        char col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        char col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        char col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        if(col1 != checkSum || col2 != checkSum || col3 != checkSum)
        {
            return false;
        }
        char diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        char diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
        if(diag1 != checkSum || diag2 != checkSum)
        {
            return false;
        }
        return true;
    }
};