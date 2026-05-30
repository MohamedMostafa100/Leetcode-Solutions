class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
        return solve(dp, n, k);
    }
private:
    long long solve(vector<vector<long long>>& dp, int n, int k)
    {
        if(k == 0)
        {
            if(n == 0)
            {
                return 1;
            }
            return 0;
        }
        else if(n == 0)
        {
            return 0;
        }
        if(dp[n][k] == -1)
        {
            dp[n][k] = 0;
            dp[n][k] = (dp[n][k] + solve(dp, n - 1, k - 1)) % 1000000007;
            dp[n][k] = (dp[n][k] + ((solve(dp, n - 1, k) * (n - 1)) % 1000000007)) % 1000000007;
        }
        return dp[n][k] % 1000000007;
    }
};