class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(nums1, nums2, dp, 0, 0);
    }
private:
    int solve(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int i, int j)
    {
        if(i == nums1.size() || j == nums2.size())
        {
            return INT_MIN / 2;
        }
        if(dp[i][j] == -1)
        {
            dp[i][j] = INT_MIN;
            dp[i][j] = max(dp[i][j], nums1[i] * nums2[j] + max(0, solve(nums1, nums2, dp, i + 1, j + 1)));
            dp[i][j] = max(dp[i][j], solve(nums1, nums2, dp, i + 1, j));
            dp[i][j] = max(dp[i][j], solve(nums1, nums2, dp, i, j + 1));
        }
        return dp[i][j];
    }
};