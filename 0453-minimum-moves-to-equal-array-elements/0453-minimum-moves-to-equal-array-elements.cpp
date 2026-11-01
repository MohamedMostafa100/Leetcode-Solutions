class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int mn = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            mn = min(mn, nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            res += nums[i] - mn;
        }
        return res;
    }
};