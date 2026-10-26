class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] > 0 && !vis[i][j] && dfs(grid, vis, k, i, j) == 0)
                {
                    res++;
                }
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int& k, int i, int j)
    {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || vis[i][j] || grid[i][j] == 0)
        {
            return 0;
        }
        vis[i][j] = true;
        return (grid[i][j] + dfs(grid, vis, k, i + 1, j) + dfs(grid, vis, k, i, j + 1) + dfs(grid, vis, k, i - 1, j) + dfs(grid, vis, k, i, j - 1)) % k;
    }
};