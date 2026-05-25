class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n - 1] != '0')
        {
            return false;
        }
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(s[i] == '1')
            {
                dp[i] = dp[i + 1];
            }
            else
            {
                int start = i + minJump;
                if(start >= n)
                {
                    dp[i] = dp[i + 1];
                    continue;
                }
                int end = min(i + maxJump, n - 1) + 1;
                if(dp[start] - dp[end] >= 1)
                {
                    dp[i] = dp[i + 1] + 1;
                }
                else
                {
                    dp[i] = dp[i + 1];
                }
            }
        }
        if(dp[0] - dp[1] == 1)
        {
            return true;
        }
        return false;
    }
};