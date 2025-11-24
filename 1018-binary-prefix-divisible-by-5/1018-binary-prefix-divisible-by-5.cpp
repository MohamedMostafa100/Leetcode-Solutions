class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int cur = 0;
        for(auto& num : nums)
        {
            if(num == 1)
            {
                cur++;
            }
            if(cur % 5 == 0)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
            cur <<= 1;
            cur %= 5;
        }
        return res;
    }
};