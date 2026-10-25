class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0 && visited[i][j] == -1 && dfs(grid, visited, i, j) == 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j)
    {
        if(grid[i][j] == 1)
        {
            return 1;
        }
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
        {
            visited[i][j] = 0;
        }
        if(visited[i][j] == -1)
        {
            visited[i][j] = 1;
            visited[i][j] = min({dfs(grid, visited, i + 1, j), dfs(grid, visited, i, j + 1), dfs(grid, visited, i - 1, j), dfs(grid, visited, i, j - 1)});
        }
        return visited[i][j];
    }
};