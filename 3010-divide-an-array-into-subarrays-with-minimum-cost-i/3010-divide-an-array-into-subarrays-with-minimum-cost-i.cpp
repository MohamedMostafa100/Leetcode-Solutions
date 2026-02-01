class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        vector<int> mins;
        for(int i = 1; i < nums.size(); i++)
        {
            if(mins.size() < 2)
            {
                mins.push_back(nums[i]);
            }
            else
            {
                if(nums[i] < mins[1])
                {
                    mins[1] = nums[i];
                }
            }
            sort(mins.begin(), mins.end());
        }
        for(int i = 0; i < mins.size(); i++)
        {
            res += mins[i];
        }
        return res;
    }
};