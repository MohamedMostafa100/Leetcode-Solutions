class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> subGrid;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        subGrid.push_back(grid[r][c]);
                    }
                }
                int kmin = INT_MAX;
                sort(subGrid.begin(), subGrid.end());
                for (int t = 1; t < subGrid.size(); t++) {
                    if (subGrid[t] == subGrid[t - 1]) {
                        continue;
                    }
                    kmin = min(kmin, subGrid[t] - subGrid[t - 1]);
                }
                if (kmin != INT_MAX) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
};