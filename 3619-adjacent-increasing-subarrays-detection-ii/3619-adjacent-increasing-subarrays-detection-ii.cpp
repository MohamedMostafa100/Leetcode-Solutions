class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res = 0;
        int count = 1;
        int preCount = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                count++;
            }
            else
            {
                preCount = count;
                count = 1;
            }
            res = max(res, min(preCount, count));
            res = max(res, count / 2);
        }
        return res;
    }
};