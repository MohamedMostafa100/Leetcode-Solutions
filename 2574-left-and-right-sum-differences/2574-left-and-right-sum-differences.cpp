class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = abs(res[i] - leftSum);
            leftSum += nums[i];
            res[nums.size() - i - 1] = abs(res[nums.size() - i - 1] - rightSum);
            rightSum += nums[nums.size() - i - 1];
        }
        return res;
    }
};