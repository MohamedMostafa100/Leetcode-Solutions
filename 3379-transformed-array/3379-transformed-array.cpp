class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                result.push_back(nums[i]);
            }
            else
            {
                result.push_back(nums[(i + (nums[i] / abs(nums[i])) * (abs(nums[i]) % n) + n) % n]);
            }
        }
        return result;
    }
};