class Solution {
public:
    double soupServings(int n) {
        double res = 0;
        if(n > 5000)
        {
            return 1;
        }
        n = ceil((double)n / 25);
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
            dp[a][b] += 0.25 * solve(dp, a - 4, b);
            dp[a][b] += 0.25 * solve(dp, a - 3, b - 1);
            dp[a][b] += 0.25 * solve(dp, a - 2, b - 2);
            dp[a][b] += 0.25 * solve(dp, a - 1, b - 3);
        }
        return dp[a][b];
    }
};