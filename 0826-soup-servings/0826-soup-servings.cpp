class Solution {
public:
    double soupServings(int n) {
        double res = 0;
        if(n > 5000)
        {
            return 1;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        res = solve(dp, n, n);
        return res;
    }
private:
    double solve(vector<vector<double>>& dp, int a, int b)
    {
        if(a <= 0 || b <= 0)
        {
            if(a < b)
            {
                return 1;
            }
            else if(a == b)
            {
                return 0.5;
            }
            return 0;
        }
        if(dp[a][b] == -1)
        {
            dp[a][b] = 0;
            dp[a][b] += 0.25 * solve(dp, a - 100, b);
            dp[a][b] += 0.25 * solve(dp, a - 75, b - 25);
            dp[a][b] += 0.25 * solve(dp, a - 50, b - 50);
            dp[a][b] += 0.25 * solve(dp, a - 25, b - 75);
        }
        return dp[a][b];
    }
};