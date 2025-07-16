class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int prev = nums[0];
        int alternating = 1;
        int even = 0;
        int odd = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 != prev % 2)
            {
                alternating++;
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

        return max({alternating, even, odd});
    }
};