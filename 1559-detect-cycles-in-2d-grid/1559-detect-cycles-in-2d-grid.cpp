class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!visited[i][j] && dfs(grid, visited, i, j, grid[i][j], -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, char prev, int dir)
    {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != prev)
        {
            return false;
        }
        if(visited[i][j])
        {
            return true;
        }
        else
        {
            visited[i][j] = true;
            if(dir != 1 && dfs(grid, visited, i + 1, j, grid[i][j], 0))
            {
                return true;
            }
            if(dir != 0 && dfs(grid, visited, i - 1, j, grid[i][j], 1))
            {
                return true;
            }
            if(dir != 3 && dfs(grid, visited, i, j + 1, grid[i][j], 2))
            {
                return true;
            }
            if(dir != 2 && dfs(grid, visited, i, j - 1, grid[i][j], 3))
            {
                return true;
            }
        }
        return false;
    }
};