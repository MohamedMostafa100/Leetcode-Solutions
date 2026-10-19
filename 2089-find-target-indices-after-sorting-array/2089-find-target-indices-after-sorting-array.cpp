class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int sm = 0;
        int eq = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < target)
            {
                sm++;
            }
            else if(nums[i] == target)
            {
                eq++;
            }
        }
        for(int i = sm; i < sm + eq; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};