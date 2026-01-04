class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int tot = nums[i] + 1;
            int size = 2;
            for(int j = 2; j <= sqrt(nums[i]); j++)
            {
                if(nums[i] % j == 0)
                {
                    tot += j + (nums[i] / j);
                    if(j == (nums[i] / j))
                    {
                        size++;
                    }
                    else
                    {
                        size += 2;
                    }
                }
            }
            if(size == 4)
            {
                res += tot;
            }
        }
        return res;
    }
};