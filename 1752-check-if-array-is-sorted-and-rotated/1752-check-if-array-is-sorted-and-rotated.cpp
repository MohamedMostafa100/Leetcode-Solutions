class Solution {
public:
    bool check(vector<int>& nums) {
        bool turn = false;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                if(turn)
                {
                    return false;
                }
                turn = true;
            }
        }
        if(turn && nums[0] < nums[nums.size() - 1])
        {
            return false;
        }
        return true;
    }
};