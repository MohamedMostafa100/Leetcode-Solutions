class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sumL = 0;
        int sumR = sum;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            sumL += nums[i];
            sumR -= nums[i];
            if(abs(sumL - sumR) % 2 == 0)
            {
                res++;
            }
        }
        return res;
    }
};