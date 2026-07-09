class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> unions = {0};
        int curId = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] > maxDiff)
            {
                curId++;
            }
            unions.push_back(curId);
        }
        for(int i = 0; i < queries.size(); i++)
        {
            if(unions[queries[i][0]] == unions[queries[i][1]])
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};