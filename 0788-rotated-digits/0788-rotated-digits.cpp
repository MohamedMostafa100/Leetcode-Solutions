class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i <= n; i++)
        {
            if(i < 10)
            {
                if(i == 0 || i == 1 || i == 8)
                {
                    dp[i] = 1;
                }
                else if(i == 3 || i == 4 || i == 7)
                {
                    dp[i] = 0;
                }
                else
                {
                    dp[i] = 2;
                    res++;
                }
            }
            else
            {
                dp[i] = min(dp[i / 10] * dp[i % 10], 2);
                if(dp[i] == 2)
                {
                    res++;
                }
            }
        }
        return res;
    }
};