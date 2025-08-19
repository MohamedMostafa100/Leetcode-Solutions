class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int len = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                len++;
            }
            else
            {
                len = 0;
            }
            res += len;
        }
        return res;
    }
};