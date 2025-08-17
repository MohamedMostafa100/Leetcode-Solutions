class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double res = 0;
        vector<double> dp(n + 1, 0);
        double winSum = 0;
        if(k == 0 || k - 1 + maxPts <= n)
        {
            return 1;
        }
        dp[0] = 1;
        winSum = dp[0];
        for(int i = 1; i <= n; i++)
        {
            dp[i] = winSum / maxPts;
            if(i < k)
            {
                winSum += dp[i];
            }
            else
            {
                res += dp[i];
            }
            if(i >= maxPts)
            {
                winSum -= dp[i - maxPts];
            }
        }
        return res;
    }
};