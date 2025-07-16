class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int prev = nums[0];
        int changing = 1;
        int even = 0;
        int odd = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != prev % 2)
            {
                changing++;
                prev = nums[i];
            }
            if(nums[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        } 

        return max({changing, even, odd});
    }
};