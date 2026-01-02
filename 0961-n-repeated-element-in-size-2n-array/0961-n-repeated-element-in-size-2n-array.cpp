class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 3; i += 3)
        {
            if(nums[i] == nums[i + 1] || nums[i] == nums[i + 2] || nums[i] == nums[i + 3])
            {
                return nums[i];
            }
            else if(nums[i + 1] == nums[i + 2] || nums[i + 1] == nums[i + 3])
            {
                return nums[i + 1];
            }
            else if(nums[i + 2] == nums[i + 3])
            {
                return nums[i + 2];
            }
        }
        return -1;
    }
};