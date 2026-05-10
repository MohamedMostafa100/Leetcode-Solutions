class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<pair<int, bool>> dp(nums.size(), {0, false});
        dp[nums.size() - 1] = {0, true};
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j] - nums[i] <= target && nums[j] - nums[i] >= -target && dp[j].second)
                {
                    dp[i].first = max(dp[i].first, dp[j].first + 1);
                    dp[i].second = true;
                }
            }
        }
        if(dp[0].first == 0)
        {
            return -1;
        }
        return dp[0].first;
    }
};