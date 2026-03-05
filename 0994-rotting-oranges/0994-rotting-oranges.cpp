class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        queue<vector<int>> rot; 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    rot.push({i, j, 0});
                }
            }
        }
        while(!rot.empty())
        {
            int i = rot.front()[0];
            int j = rot.front()[1];
            int time = rot.front()[2];
            res = time;
            rot.pop();
            if(i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                rot.push({i - 1, j, time + 1});
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                rot.push({i + 1, j, time + 1});
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                rot.push({i, j - 1, time + 1});
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                rot.push({i, j + 1, time + 1});
            }
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return res;
    }
};