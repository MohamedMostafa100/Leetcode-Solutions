#define MOD 1000000007
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long res = -1;
        vector<vector<pair<long long, long long>>> dp(grid.size(), vector<pair<long long, long long>>(grid[0].size(), {LLONG_MIN, LLONG_MAX}));
        int m = grid.size();
        int n = grid[0].size();
        dp[m - 1][n - 1] = {grid[m - 1][n - 1], grid[m - 1][n - 1]};
        res = max(res, solve(grid, dp, 0, 0).first % MOD);
        return res;
    }
private:
    pair<long long, long long> solve(vector<vector<int>>& grid, vector<vector<pair<long long, long long>>>& dp, int i, int j)
    {
        if(i == grid.size() || j == grid[0].size())
        {
            return {LLONG_MIN, LLONG_MAX};
        }
        if(dp[i][j] == make_pair(LLONG_MIN, LLONG_MAX))
        {
            pair<long long, long long> r = solve(grid, dp, i, j + 1);
            if(r != make_pair(LLONG_MIN, LLONG_MAX))
            {
                dp[i][j].first = max({dp[i][j].first, grid[i][j] * r.first, grid[i][j] * r.second});
                dp[i][j].second = min({dp[i][j].second, grid[i][j] * r.first, grid[i][j] * r.second});
            }
            pair<long long, long long> d = solve(grid, dp, i + 1, j);
            if(d != make_pair(LLONG_MIN, LLONG_MAX))
            {
                dp[i][j].first = max({dp[i][j].first, grid[i][j] * d.first, grid[i][j] * d.second});
                dp[i][j].second = min({dp[i][j].second, grid[i][j] * d.first, grid[i][j] * d.second});
            }
        }
        return dp[i][j];
    }
};