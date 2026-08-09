class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() * 2 + 1, -1));
        int tot = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            tot += piles[i];
        }
        return solve(piles, dp, tot, 0, 1);
    }
private:
    int solve(vector<int>& piles, vector<vector<int>>& dp, int rem, int i, int m)
    {
        if(i + 2 * m >= piles.size())
        {
            return rem;
        }
        if(dp[i][m] == -1)
        {
            int res = INT_MAX;
            int curRem = rem;
            for(int x = 1; x <= 2 * m; x++)
            {
                curRem -= piles[i + x - 1];
                res = min(res, solve(piles, dp, curRem, i + x, max(m, x)));
            }
            dp[i][m] = rem - res;
        }
        return dp[i][m];
    }
};