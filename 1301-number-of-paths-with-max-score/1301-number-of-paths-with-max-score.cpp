class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].length();
        vector<vector<int>> dp1(m, vector<int>(n, -1));
        vector<vector<long long>> dp2(m, vector<long long>(n, -1));
        dp1[0][0] = 0;
        dp2[0][0] = 1;
        int maxSum = max(0, solve1(board, dp1, m - 1, n - 1));
        int maxSumPaths = solve2(board, dp1, dp2, m - 1, n - 1, maxSum);
        return {maxSum, maxSumPaths};
    }
private:
    int solve1(vector<string>& board, vector<vector<int>>& dp1, int i, int j)
    {
        if(i < 0 || j < 0 || board[i][j] == 'X')
        {
            return INT_MIN / 2;
        }
        if(dp1[i][j] == -1)
        {
            dp1[i][j] = INT_MIN / 2;
            int toAdd = 0;
            if(board[i][j] != 'S')
            {
                toAdd = board[i][j] - '0';
            }
            dp1[i][j] = max(dp1[i][j], solve1(board, dp1, i - 1, j) + toAdd);
            dp1[i][j] = max(dp1[i][j], solve1(board, dp1, i, j - 1) + toAdd);
            dp1[i][j] = max(dp1[i][j], solve1(board, dp1, i - 1, j - 1) + toAdd);
        }
        return dp1[i][j];
    }
    int solve2(vector<string>& board, vector<vector<int>>& dp1, vector<vector<long long>>& dp2, int i, int j, int curSum)
    {
        if(i < 0 || j < 0 || board[i][j] == 'X' || dp1[i][j] != curSum)
        {
            return 0;
        }
        if(dp2[i][j] == -1)
        {
            dp2[i][j] = 0;
            if(board[i][j] != 'S')
            {
                curSum -= (board[i][j] - '0');
            }
            dp2[i][j] = (dp2[i][j] + solve2(board, dp1, dp2, i - 1, j, curSum)) % 1000000007;
            dp2[i][j] = (dp2[i][j] + solve2(board, dp1, dp2, i, j - 1, curSum)) % 1000000007;
            dp2[i][j] = (dp2[i][j] + solve2(board, dp1, dp2, i - 1, j - 1, curSum)) % 1000000007;
        }
        return dp2[i][j] % 1000000007;
    }
};