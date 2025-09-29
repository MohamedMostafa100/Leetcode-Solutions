class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        return solve(values, dp, 0, (int)values.size() - 1);
    }
private:
    int solve(vector<int>& values, vector<vector<int>>& dp, int i, int j)
    {
        if(j - i < 2)
        {
            return 0;
        }
        else if(j - i == 2)
        {
            return values[i] * values[i + 1] * values[j];
        }
        if(dp[i][j] == -1)
        {
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + solve(values, dp, i, k) + solve(values, dp, k, j));
            }
        }
        return dp[i][j];
    }
};