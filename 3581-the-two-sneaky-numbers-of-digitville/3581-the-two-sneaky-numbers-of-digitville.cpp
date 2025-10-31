class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        vector<bool> exist(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            if(exist[nums[i]])
            {
                res.push_back(nums[i]);
            }
            else
            {
                exist[nums[i]] = true;
            }
        }
        return res;
    }
};