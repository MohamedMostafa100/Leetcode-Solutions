class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                res += solve(matrix, dp, i, j);
            }
        }
        return res;
    }

private:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i,
              int j) {
        if (i == dp.size() || j == dp[0].size() || matrix[i][j] == 0) {
            return 0;
        }
        if (dp[i][j] == -1) {
            int right = solve(matrix, dp, i, j + 1);
            int down = solve(matrix, dp, i + 1, j);
            int diag = solve(matrix, dp, i + 1, j + 1);
            dp[i][j] = 1 + min({right, down, diag});
        }
        return dp[i][j];
    }
};