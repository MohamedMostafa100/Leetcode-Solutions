class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;
        vector<vector<int>> dp(k, vector<int>(k, 0));
        for(int i = 0; i < nums.size(); i++)
        {
            int mod = nums[i] % k;
            for(int j = 0; j < k; j++)
            {
                int diff = (j - mod + k) % k;
                dp[mod][j] = dp[diff][j] + 1;
                res = max(res, dp[mod][j]);
            }
        }

        return res;
    }
};