class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 3));
        int safeCells = m * n;
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 1;
            safeCells--;
        }

        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 0;
            safeCells--;
        }

        for (int i = 0; i < guards.size(); i++) {

            // right
            for (int j = guards[i][1] + 1; j < n; j++) {
                if (grid[guards[i][0]][j] == 3) {
                    grid[guards[i][0]][j] = 2;
                    safeCells--;
                } else if (grid[guards[i][0]][j] == 0 ||
                           grid[guards[i][0]][j] == 1) {
                    break;
                }
            }

            // left
            for (int j = guards[i][1] - 1; j >= 0; j--) {
                if (grid[guards[i][0]][j] == 3) {
                    grid[guards[i][0]][j] = 2;
                    safeCells--;
                } else if (grid[guards[i][0]][j] == 0 ||
                           grid[guards[i][0]][j] == 1) {
                    break;
                }
            }

            // down
            for (int j = guards[i][0] + 1; j < m; j++) {
                if (grid[j][guards[i][1]] == 3) {
                    grid[j][guards[i][1]] = 2;
                    safeCells--;
                } else if (grid[j][guards[i][1]] == 0 ||
                           grid[j][guards[i][1]] == 1) {
                    break;
                }
            }

            // up
            for (int j = guards[i][0] - 1; j >= 0; j--) {
                if (grid[j][guards[i][1]] == 3) {
                    grid[j][guards[i][1]] = 2;
                    safeCells--;
                } else if (grid[j][guards[i][1]] == 0 ||
                           grid[j][guards[i][1]] == 1) {
                    break;
                }
            }
        }
        return safeCells;
    }
};