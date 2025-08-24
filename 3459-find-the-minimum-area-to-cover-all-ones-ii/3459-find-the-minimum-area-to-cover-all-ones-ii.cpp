class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        vector<vector<int>> gridTransposed(grid[0].size(), vector<int>(grid.size()));
        for(int i = 0; i < gridTransposed.size(); i++)
        {
            for(int j = 0; j < gridTransposed[i].size(); j++)
            {
                gridTransposed[i][j] = grid[j][i];
            }
        }
        return min(solve(grid), solve(gridTransposed));
    }
private:
    int solve(vector<vector<int>>& grid)
    {
        int res = INT_MAX;
        //3 Vertical Splits
        for(int i = 0; i < grid[0].size() - 2; i++)
        {
            for(int j = i + 1; j < grid[0].size() - 1; j++)
            {
                int split1 = minimumArea(grid, 0, grid.size() - 1, 0, i);
                int split2 = minimumArea(grid, 0, grid.size() - 1, i + 1, j);
                int split3 = minimumArea(grid, 0, grid.size() - 1, j + 1, grid[0].size() - 1);
                res = min(res, split1 + split2 + split3);
            }
        }
        //1 Vertical and 2 Horizontal Splits
        for(int i = 0; i < grid.size() - 1; i++)
        {
            for(int j = 0; j < grid[0].size() - 1; j++)
            {
                int split1 = minimumArea(grid, 0, grid.size() - 1, 0, j);
                int split2 = minimumArea(grid, 0, i, j + 1, grid[0].size() - 1);
                int split3 = minimumArea(grid, i + 1, grid.size() - 1, j + 1, grid[0].size() - 1);
                res = min(res, split1 + split2 + split3);
                split1 = minimumArea(grid, 0, i, 0, j);
                split2 = minimumArea(grid, i + 1, grid.size() - 1, 0, j);
                split3 = minimumArea(grid, 0, grid.size() - 1, j + 1, grid[0].size() - 1);
                res = min(res, split1 + split2 + split3);
            }
        }
        return res;
    }
    int minimumArea(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        pair<int, int> topLeft = {-1, -1};
        pair<int, int> bottomRight = {-1, -1};
        for(int i = rowStart; i <= rowEnd; i++)
        {
            for(int j = colStart; j <= colEnd; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(topLeft.first == -1)
                    {
                        topLeft = {i, j};
                        bottomRight = {i, j};
                    }
                    else
                    {
                        topLeft.second = min(topLeft.second, j);
                        bottomRight = {i, max(bottomRight.second, j)};
                    }
                }
            }
        }
        return topLeft.first != -1 ? (bottomRight.first - topLeft.first + 1) * (bottomRight.second - topLeft.second + 1) : INT_MAX / 3;
    }
};