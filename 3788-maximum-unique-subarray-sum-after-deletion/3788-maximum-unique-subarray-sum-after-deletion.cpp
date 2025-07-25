class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> inArr;
        int res = -1;
        int sum = 0;
        int maxNeg = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= 0 && !inArr.count(nums[i]))
            {
                sum += nums[i];
                res = max(res, sum);
                inArr.insert(nums[i]);
            }
            else if(nums[i] < 0)
            {
                maxNeg = max(maxNeg, nums[i]);
            }
        }
        if(res == -1)
        {
            return maxNeg;
        }
        else
        {
            return res;
        }
    }
};