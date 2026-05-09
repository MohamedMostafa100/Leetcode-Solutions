class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m / 2, n / 2);
        int prem = 2 * m + 2 * n - 4;
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int l = 0; l < layers; l++)
        {
            int steps = k % prem;
            int idx = (prem - steps) % prem; 
            vector<int> shifted(prem, 0);
            for(int j = l; j < n - l - 1; j++)
            {
                shifted[idx] = grid[l][j];
                idx = (idx + 1) % prem;
            }
            for(int i = l; i < m - l - 1; i++)
            {
                shifted[idx] = grid[i][n - l - 1];
                idx = (idx + 1) % prem;
            }
            for(int j = n - l - 1; j > l; j--)
            {
                shifted[idx] = grid[m - l - 1][j];
                idx = (idx + 1) % prem;
            }
            for(int i = m - l - 1; i > l; i--)
            {
                shifted[idx] = grid[i][l];
                idx = (idx + 1) % prem;
            }
            idx = 0;
            for(int j = l; j < n - l - 1; j++)
            {
                res[l][j] = shifted[idx];
                idx++;
            }
            for(int i = l; i < m - l - 1; i++)
            {
                res[i][n - l - 1] = shifted[idx];
                idx++;
            }
            for(int j = n - l - 1; j > l; j--)
            {
                res[m - l - 1][j] = shifted[idx];
                idx++;
            }
            for(int i = m - l - 1; i > l; i--)
            {
                res[i][l] = shifted[idx];
                idx++;
            }
            prem -= 8;
        }
        return res;
    }
};