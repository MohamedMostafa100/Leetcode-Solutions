class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        int mx = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            res = max(res, (mx - 1) * (nums[i] - 1));
            mx = max(mx, nums[i]);
        }
        return res;
    }
};