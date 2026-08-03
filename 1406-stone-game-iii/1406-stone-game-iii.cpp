class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int res = 0;
        vector<int> dp(stoneValue.size(), INT_MIN);
        res = solve(stoneValue, dp, 0);
        if (res > 0) {
            return "Alice";
        } else if (res < 0) {
            return "Bob";
        }
        return "Tie";
    }

private:
    int solve(vector<int>& stoneValue, vector<int>& dp, int i) {
        if (i == stoneValue.size()) {
            return 0;
        }
        if (dp[i] == INT_MIN) {
            dp[i] = max(dp[i], stoneValue[i] - solve(stoneValue, dp, i + 1));
            if (i + 1 < stoneValue.size()) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] -
                                   solve(stoneValue, dp, i + 2));
            }
            if (i + 2 < stoneValue.size()) {
                dp[i] =
                    max(dp[i], stoneValue[i] + stoneValue[i + 1] +
                                 stoneValue[i + 2] - solve(stoneValue, dp, i + 3));
            }
        }
        return dp[i];
    }
};