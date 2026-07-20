class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int curPos = i * n + j;
                int newPos = (curPos + k) % (m * n);
                res[newPos / n][newPos % n] = grid[i][j];
            }
        }
        return res;
    }
};