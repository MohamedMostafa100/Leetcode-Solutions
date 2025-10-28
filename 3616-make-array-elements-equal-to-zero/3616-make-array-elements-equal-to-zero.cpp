class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        vector<int> pre(nums.size());
        vector<int> suff(nums.size());
        int preSum = 0;
        int sufSum = 0;
        for(int i = 0, j = nums.size() - 1; i < nums.size(), j >= 0;i++, j--)
        {
            preSum += nums[i];
            sufSum += nums[j];
            pre[i] = preSum;
            suff[j] = sufSum;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(pre[i] == suff[i])
                {
                    res += 2;
                }
                else if(abs(pre[i] - suff[i]) == 1)
                {
                    res++;
                }
            }
        }
        return res;
    }
};