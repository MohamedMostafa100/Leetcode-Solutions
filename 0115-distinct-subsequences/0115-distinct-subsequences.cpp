class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length() == t.length())
        {
            return s == t;
        }
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, dp, 0, 0);
    }
private:
    int solve(string& s, string& t, vector<vector<int>>& dp, int i, int match)
    {
        if(match == t.length())
        {
            return 1;
        }
        if(i == s.length())
        {
            return 0;
        }
        if(dp[i][match] == -1)
        {
            dp[i][match] = 0;
            if(s[i] == t[match])
            {
                dp[i][match] += solve(s, t, dp, i + 1, match + 1);
            }
            dp[i][match] += solve(s, t, dp, i + 1, match);
        }
        return dp[i][match];
    }
};