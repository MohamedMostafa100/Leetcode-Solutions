class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        pair<int, int> topLeft = {-1, -1};
        pair<int, int> bottomRight = {-1, -1};
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
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
        return (bottomRight.first - topLeft.first + 1) * (bottomRight.second - topLeft.second + 1);
    }
};