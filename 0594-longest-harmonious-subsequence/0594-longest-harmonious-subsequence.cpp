class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }


        for(auto& it : mp)
        {
            if(mp.find(it.first + 1) != mp.end())
            {
                res = max(res, it.second + mp[it.first + 1]);
            }
        }

        return res;
    }
};