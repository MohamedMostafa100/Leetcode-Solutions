class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<vector<vector<int>>>> dp(grid.size(), vector<vector<vector<int>>>(grid[0].size(), vector<vector<int>>(4, vector<int>(2, -1))));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    res = max(res, 1 + solve(grid, dp, i - 1, j - 1, 0, 0, 1));
                    res = max(res, 1 + solve(grid, dp, i - 1, j + 1, 1, 0, 1));
                    res = max(res, 1 + solve(grid, dp, i + 1, j + 1, 2, 0, 1));
                    res = max(res, 1 + solve(grid, dp, i + 1, j - 1, 3, 0, 1));
                }
            }
        }
        return res;
    }
private:
    int solve(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp, int i, int j, int dir, int turn, int prev)
    {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
        {
            return 0;
        }
        if((prev == 1 && grid[i][j] != 2) || (prev == 2 && grid[i][j] != 0) || (prev == 0 && grid[i][j] != 2))
        {
            return 0;
        }
        if(dp[i][j][dir][turn] == -1)
        {
            dp[i][j][dir][turn] = 1;
            if(dir == 0)
            {
                int noTurn = solve(grid, dp, i - 1, j - 1, 0, turn, grid[i][j]);
                int doTurn = 0;
                if(!turn)
                {
                    doTurn = solve(grid, dp, i - 1, j + 1, 1, 1, grid[i][j]);
                }
                dp[i][j][dir][turn] += max(noTurn, doTurn);
            }
            else if(dir == 1)
            {
                int noTurn = solve(grid, dp, i - 1, j + 1, 1, turn, grid[i][j]);
                int doTurn = 0;
                if(!turn)
                {
                    doTurn = solve(grid, dp, i + 1, j + 1, 2, 1, grid[i][j]);
                }
                dp[i][j][dir][turn] += max(noTurn, doTurn);
            }
            else if(dir == 2)
            {
                int noTurn = solve(grid, dp, i + 1, j + 1, 2, turn, grid[i][j]);
                int doTurn = 0;
                if(!turn)
                {
                    doTurn = solve(grid, dp, i + 1, j - 1, 3, 1, grid[i][j]);
                }
                dp[i][j][dir][turn] += max(noTurn, doTurn);
            }
            else if(dir == 3)
            {
                int noTurn = solve(grid, dp, i + 1, j - 1, 3, turn, grid[i][j]);
                int doTurn = 0;
                if(!turn)
                {
                    doTurn = solve(grid, dp, i - 1, j - 1, 0, 1, grid[i][j]);
                }
                dp[i][j][dir][turn] += max(noTurn, doTurn);
            }
        }
        return dp[i][j][dir][turn];
    }
};