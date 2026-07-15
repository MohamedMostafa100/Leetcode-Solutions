class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int maxNum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            maxNum = max(maxNum, nums[i]);
        }
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 1, -1)));
        return solve(nums, dp, 0, 0, 0);
    }
private:
    int solve(vector<int>& nums, vector<vector<vector<int>>>& dp, int i, int g1, int g2)
    {
        if(i == nums.size())
        {
            if(g1 > 0 && g2 > 0 && g1 == g2)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][g1][g2] == -1)
        {
            dp[i][g1][g2] = 0;
            dp[i][g1][g2] = (dp[i][g1][g2] + solve(nums, dp, i + 1, g1 == 0 ? nums[i] : gcd(g1, nums[i]), g2)) % 1000000007;
            dp[i][g1][g2] = (dp[i][g1][g2] + solve(nums, dp, i + 1, g1, g2 == 0 ? nums[i] : gcd(g2, nums[i]))) % 1000000007;
            dp[i][g1][g2] = (dp[i][g1][g2] + solve(nums, dp, i + 1, g1, g2)) % 1000000007;
        }
        return dp[i][g1][g2] % 1000000007;
    }
};