#define MOD 1000000007
typedef long long ll;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n , vector<ll>(3, -1)));
        return solve(grid, dp, 0, 0, 0);
    }
private:
    int solve(vector<vector<int>>& grid, vector<vector<vector<ll>>>& dp, int i, int j, int dir)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
        {
            return 0;
        }
        if(i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if(dp[i][j][dir] == -1)
        {
            dp[i][j][dir] = 0;
            if(grid[i][j] == 1)
            {
                if(dir == 1)
                {
                    dp[i][j][dir] = (dp[i][j][dir] + solve(grid, dp, i + 1, j, 2)) % MOD;
                }
                else
                {
                    dp[i][j][dir] = (dp[i][j][dir] + solve(grid, dp, i, j + 1, 1)) % MOD;
                }
            }
            else
            {
                dp[i][j][dir] = (dp[i][j][dir] + solve(grid, dp, i + 1, j, 2)) % MOD;
                dp[i][j][dir] = (dp[i][j][dir] + solve(grid, dp, i, j + 1, 1)) % MOD;
            }
        }
        return dp[i][j][dir] % MOD;
    }
    int m;
    int n;
};