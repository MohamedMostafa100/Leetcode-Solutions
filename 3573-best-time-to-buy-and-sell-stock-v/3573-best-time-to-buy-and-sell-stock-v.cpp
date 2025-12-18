class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> dp(prices.size(), vector<vector<long long>>(k + 1, vector<long long>(3, -1)));
        return solve(prices, dp, 0, k, 0);
    }
private:
    long long solve(vector<int>& prices, vector<vector<vector<long long>>>& dp, int i, int k, int s)
    {
        if(i == prices.size())
        {
            if(s == 0)
            {
                return 0;
            }
            return LLONG_MIN / 2;
        }
        if(dp[i][k][s] == -1)
        {
            dp[i][k][s] = LLONG_MIN;
            dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, s));
            if(k > 0)
            {
                if(s == 0)
                {
                    dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, 1) - prices[i]);
                    dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, 2) + prices[i]);
                }
                else if(s == 1)
                {
                    dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k - 1, 0) + prices[i]);
                }
                else
                {
                    dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k - 1, 0) - prices[i]);
                }
            }
        }
        return dp[i][k][s];
    }
};