class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        bool nonZero = false;
        for(int i = 0; i < n; i++)
        {
            xorSum ^= nums[i];
            if(nums[i])
            {
                nonZero = true;
            }
        }
        return xorSum > 0 ? n : nonZero ? n - 1 : 0;
    }
};