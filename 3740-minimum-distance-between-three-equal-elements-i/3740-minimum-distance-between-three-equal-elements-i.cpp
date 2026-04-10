class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, vector<int>> idxs;
        for(int i = 0; i < nums.size(); i++)
        {
            idxs[nums[i]].push_back(i);
        }
        for(auto idx : idxs)
        {
            if(idx.second.size() >= 3)
            {
                vector<int> good = idx.second;
                for(int i = 0, k = 2; k < good.size(); i++, k++)
                {
                    res = min(res, 2 * (good[k] - good[i]));
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};