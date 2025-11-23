class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
        return solve(nums, dp, 0, 0);
    }
private:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int mod)
    {
        if(i == nums.size())
        {
            if(mod == 0)
            {
                return 0;
            }
            else
            {
                return INT_MIN;
            }    
        }
        if(dp[i][mod] == -1)
        {
            dp[i][mod] = 0;
            dp[i][mod] = max(solve(nums, dp, i + 1, mod), solve(nums, dp, i + 1, (mod + nums[i]) % 3) + nums[i]);
        }
        return dp[i][mod];
    }
};