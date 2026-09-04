class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int res = nums.size();
        vector<int> pre(nums.size(), 0);
        int minNum = INT_MAX;
        int curMax = 0;
        int curMin = INT_MAX;
        int r = nums.size() - 1;
        for (int l = 0; l < nums.size(); l++) {
            curMax = max(curMax, nums[l]);
            curMin = min(curMin, nums[r]);
            pre[l] += curMax;
            pre[r] -= curMin;
            if (l >= r) {
                if (pre[l] <= k) {
                    res = min(res, l);
                }
                if (pre[r] <= k) {
                    res = min(res, r);
                }
            }
            r--;
        }
        return res != nums.size() ? res : -1;
    }
};