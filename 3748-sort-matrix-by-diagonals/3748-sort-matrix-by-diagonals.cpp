class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for (char i = 1; i < grid.size(); i++) {
            diagSort(grid, 0, i, true);
        }
        for (char i = 0; i < grid.size(); i++) {
            diagSort(grid, i, 0, false);
        }
        return grid;
    }

private:
    void diagSort(vector<vector<int>>& grid, char i, char j, bool asc) {
        while (i < grid.size() && j < grid.size()) {
            int targetNum = grid[i][j];
            char targetNumX = i;
            char targetNumY = j;
            char x = i + 1;
            char y = j + 1;
            while (x < grid.size() && y < grid.size()) {
                if (asc) {
                    if (grid[x][y] < targetNum) {
                        targetNum = grid[x][y];
                        targetNumX = x;
                        targetNumY = y;
                    }
                }
                else
                {
                    if (grid[x][y] > targetNum) {
                        targetNum = grid[x][y];
                        targetNumX = x;
                        targetNumY = y;
                    }
                }
                x++;
                y++;
            }
            int temp = grid[i][j];
            grid[i][j] = grid[targetNumX][targetNumY];
            grid[targetNumX][targetNumY] = temp;
            i++;
            j++;
        }
    }
};