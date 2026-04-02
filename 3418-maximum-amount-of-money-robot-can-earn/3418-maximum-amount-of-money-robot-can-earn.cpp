class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        dp[m - 1][n - 1][2] = coins[m - 1][n - 1];
        if(coins[m - 1][n - 1] >= 0)
        {
            dp[m - 1][n - 1][0] = coins[m - 1][n - 1];
            dp[m - 1][n - 1][1] = coins[m - 1][n - 1];
        }
        else
        {
            dp[m - 1][n - 1][0] = 0;
            dp[m - 1][n - 1][1] = 0;
        }
        return solve(coins, dp, 0, 0, 0);
    }
private:
    int solve(vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int i, int j, int nt)
    {
        if(i == coins.size() || j == coins[0].size())
        {
            return -250000000;
        }
        if(dp[i][j][nt] == INT_MIN)
        {
            dp[i][j][nt] = -250000000;
            dp[i][j][nt] = max(dp[i][j][nt], solve(coins, dp, i + 1, j, nt) + coins[i][j]);
            dp[i][j][nt] = max(dp[i][j][nt], solve(coins, dp, i, j + 1, nt) + coins[i][j]);
            if(coins[i][j] < 0 && nt < 2)
            {
                dp[i][j][nt] = max(dp[i][j][nt], solve(coins, dp, i + 1, j, nt + 1));
                dp[i][j][nt] = max(dp[i][j][nt], solve(coins, dp, i, j + 1, nt + 1));
            }
        }
        return dp[i][j][nt];
    }
};