class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, INT_MIN)));
        int res = solve(grid, dp, 0, 0, 0, k);
        return res >= 0 ? res : -1;
    }
private:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j, int cost, int k)
    {
        if(i == grid.size() || j == grid[0].size())
        {
            return INT_MIN / 2;
        }
        cost += (grid[i][j] > 0 ? 1 : 0);
        if(cost > k)
        {
            return INT_MIN / 2;
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return grid[i][j];
        }
        if(dp[i][j][cost] == INT_MIN)
        {
            dp[i][j][cost] = max(dp[i][j][cost], solve(grid, dp, i + 1, j, cost, k) + grid[i][j]);
            dp[i][j][cost] = max(dp[i][j][cost], solve(grid, dp, i, j + 1, cost, k) + grid[i][j]);
        }
        return dp[i][j][cost];
    }
};