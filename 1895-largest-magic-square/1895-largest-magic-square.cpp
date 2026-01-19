class Solution {
private:
    vector<vector<int>> rowSum;
    vector<vector<int>> colSum;
    bool checkSquare(vector<vector<int>>& grid, int row, int col, int side) {
        if (row + side - 1 >= rowSum.size() ||
            col + side - 1 >= colSum.size()) {
            return false;
        }
        int compSum =
            rowSum[row][col + side - 1] - rowSum[row][col] + grid[row][col];
        for (int i = row + 1; i < row + side; i++) {
            int sum = rowSum[i][col + side - 1] - rowSum[i][col] + grid[i][col];
            if (sum != compSum) {
                return false;
            }
        }
        for (int j = col; j < col + side; j++) {
            int sum = colSum[j][row + side - 1] - colSum[j][row] + grid[row][j];
            if (sum != compSum) {
                return false;
            }
        }
        int sumDiag1 = 0;
        int sumDiag2 = 0;
        for (int i = row, j = col; i < row + side; i++, j++) {
            sumDiag1 += grid[i][j];
        }
        for (int i = row, j = col + side - 1; i < row + side; i++, j--) {
            sumDiag2 += grid[i][j];
        }
        if (sumDiag1 != compSum || sumDiag2 != compSum) {
            return false;
        }
        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int res = 1;
        int n = grid.size();
        int m = grid[0].size();
        int maxSide = min(n, m);
        rowSum = vector<vector<int>>(n, vector<int>(m, 0));
        colSum = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
                rowSum[i][j] = sum;
            }
        }
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][j];
                colSum[j][i] = sum;
            }
        }
        for (int side = 2; side <= maxSide; side++) {
            bool flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (checkSquare(grid, i, j, side)) {
                        res = side;
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }
        }
        return res;
    }
};