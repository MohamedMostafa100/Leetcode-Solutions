class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int res = 0;
        vector<int> dp(arr.size(), -1);
        for(int i = 0; i < arr.size(); i++)
        {
            res = max(res, solve(arr, dp, i, d));
        }
        return res;
    }
private:
    int solve(vector<int>& arr, vector<int>& dp, int i, int d)
    {
        if(dp[i] == -1)
        {
            dp[i] = 1;
            for(int j = i + 1; j <= min(i + d, (int)arr.size() - 1); j++)
            {
                if(arr[i] <= arr[j])
                {
                    break;
                }
                dp[i] = max(dp[i], solve(arr, dp, j, d) + 1);
            }
            for(int j = i - 1; j >= max(i - d, 0); j--)
            {
                if(arr[i] <= arr[j])
                {
                    break;
                }
                dp[i] = max(dp[i], solve(arr, dp, j, d) + 1);
            }
        }
        return dp[i];
    }
};