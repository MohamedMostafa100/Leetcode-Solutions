class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int before = 0;
        int after = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                after++;
            }
            else
            {
                res = max(res, before + after);
                before = after;
                after = 0;
            }
        }
        res = max(res, before + after);
        return res != nums.size() ? res : res - 1;
    }
};