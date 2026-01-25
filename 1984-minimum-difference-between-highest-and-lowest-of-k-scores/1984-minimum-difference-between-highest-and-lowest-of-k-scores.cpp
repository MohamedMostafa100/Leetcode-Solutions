class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)
        {
            return 0;
        }
        int res = INT_MAX;
        int l = 0;
        sort(nums.begin(), nums.end());
        for(int r = k - 1; r < nums.size(); r++)
        {
            res = min(res, nums[r] - nums[l]);
            l++;
        }
        return res;
    }
};