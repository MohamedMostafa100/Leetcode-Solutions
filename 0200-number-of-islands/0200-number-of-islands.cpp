class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || visited[i][j] || grid[i][j] == '0')
        {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j - 1);
    }
};