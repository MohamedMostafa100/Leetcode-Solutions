class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        bool dir = false;
        int length = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                if(!dir)
                {
                    length++;
                }
                else
                {
                    length = 2;
                    dir = false;
                }
            }
            else if(nums[i] < nums[i - 1])
            {
                if(dir)
                {
                    length++;
                }
                else 
                {
                    length = 2;
                    dir = true;
                }
            }
            else
            {
                length = 1;
            }
            res = max(res, length);
        }
        return res;
    }
};