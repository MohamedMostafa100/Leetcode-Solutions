class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        unordered_set<int> found(nums.begin(), nums.end());
        int idx = 1;
        while(idx < n && nums[idx] == nums[idx - 1] + 1)
        {
            res += nums[idx];
            idx++;
        }
        while(found.count(res))
        {
            res++;
        }
        return res;
    }
};