class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0;
        int maxOr = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxOr |= nums[i];
        }
        res = solve(nums, 0, 0, maxOr);
        return res;
    }

private:
    int solve(vector<int>& nums, int idx, int cur, int& maxOr) {
        if (idx == nums.size()) {
            return cur == maxOr ? 1 : 0;
        }
        int count = 0;
        count += solve(nums, idx + 1, cur | nums[idx], maxOr);
        count += solve(nums, idx + 1, cur, maxOr);
        return count;
    }
};