class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        int maxOr = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxOr |= nums[i];
        }
        solve(nums, 0, maxOr, 0, res);
        return res;
    }

private:
    void solve(vector<int>& nums, int idx, int& maxOr, int cur, int& count) {
        if (idx == nums.size()) {
            return;
        }
        if ((cur | nums[idx]) == maxOr) {
            count++;
        }
        solve(nums, idx + 1, maxOr, cur | nums[idx], count);
        solve(nums, idx + 1, maxOr, cur, count);
    }
};