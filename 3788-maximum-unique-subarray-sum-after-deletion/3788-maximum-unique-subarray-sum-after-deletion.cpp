class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[nums.size() - 1] <= 0)
        {
            return nums[nums.size() - 1];
        }
        int res = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] <= 0)
            {
                break;
            }
            if(nums[i] != nums[i + 1])
            {
                res += nums[i];
            } 
        }
        return res;
    }
};