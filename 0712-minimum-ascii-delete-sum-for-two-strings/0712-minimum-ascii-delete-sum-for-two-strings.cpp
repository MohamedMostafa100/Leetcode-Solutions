class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return solve(s1, s2, dp, 0, 0);
    }
private:
    int solve(string& s1, string& s2, vector<vector<int>>& dp, int i, int j)
    {
        if(i == s1.length() || j == s2.length())
        {
            int rem = 0;
            while(i < s1.length())
            {
                rem += s1[i];
                i++;
            }
            while(j < s2.length())
            {
                rem += s2[j];
                j++;
            }
            return rem;
        }
        if(dp[i][j] == -1)
        {
            dp[i][j] = INT_MAX;
            if(s1[i] == s2[j])
            {
                dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i + 1, j + 1));
            }
            else
            {
                dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i + 1, j) + s1[i]);
                dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i, j + 1) + s2[j]);
            }
        }
        return dp[i][j];
    }
};