class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int count = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            int num = abs(nums[i]);
            if(num >= 1 && num <= n)
            {
                if(num == n)
                {
                    if(nums[n - 1] > 0)
                    {
                        nums[n - 1] *= -1;
                        count--;
                    }
                    else if(nums[n] > 0)
                    {
                        nums[n] *= -1;
                        count--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(nums[num - 1] > 0)
                    {
                        nums[num - 1] *= -1;
                        count--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return count == 0 ? true : false;
    }
};