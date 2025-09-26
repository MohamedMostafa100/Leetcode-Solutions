class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n * (n + 1) / 2, INT_MAX);
        return solve(triangle, dp, 0, 0);
    }
private:
    int solve(vector<vector<int>>& triangle, vector<int>& dp, int i, int j)
    {
        if(i == triangle.size())
        {
            return 0;
        }
        int idx = (i * (i + 1) / 2) + j;
        if(dp[idx] == INT_MAX)
        {
            dp[idx] = triangle[i][j];
            dp[idx] += min(solve(triangle, dp, i + 1, j), solve(triangle, dp, i + 1, j + 1));
        }
        return dp[idx];
    }
};