class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        vector<bool> range(101, false);
        char mn = 100;
        char mx = 1;
        for(char i = 0; i < nums.size(); i++)
        {
            mn = min((int)mn, nums[i]);
            mx = max((int)mx, nums[i]);
            range[nums[i]] = true;
        }
        for(char i = mn + 1; i < mx; i++)
        {
            if(!range[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};