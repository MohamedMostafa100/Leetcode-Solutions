class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(27, vector<vector<int>>(27, vector<int>(word.size(), -1)));
        return solve(word, dp, 0, 0, 0);
    }
private:
    int getDist(char x, char y)
    {
        x--;
        y--;
        if(x == -1)
        {
            return 0;
        }
        int xX = x % 6;
        int xY = x / 6;
        int yX = y % 6;
        int yY = y / 6;
        return abs(xX - yX) + abs(xY - yY);
    }
    int solve(string& word, vector<vector<vector<int>>>& dp, int i, int j, int k)
    {
        if(k == word.size())
        {
            return 0;
        }
        if(dp[i][j][k] == -1)
        {
            dp[i][j][k] = INT_MAX;
            dp[i][j][k] = min(dp[i][j][k], solve(word, dp, word[k] - 'A' + 1, j, k + 1) + getDist(i, word[k] - 'A' + 1));
            dp[i][j][k] = min(dp[i][j][k], solve(word, dp, i, word[k] - 'A' + 1, k + 1) + getDist(j, word[k] - 'A' + 1));
        }
        return dp[i][j][k];
    }
};