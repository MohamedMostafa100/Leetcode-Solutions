class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int res = 1;
        int n = nums.size();
        int l = 0;
        sort(nums.begin(), nums.end());
        for(int r = 0; r < nums.size(); r++)
        {
            while(nums[l] < (float)((float)nums[r] / k))
            {
                l++;
            }
            res = max(res, r - l + 1);
        }
        return n - res;
    }
};