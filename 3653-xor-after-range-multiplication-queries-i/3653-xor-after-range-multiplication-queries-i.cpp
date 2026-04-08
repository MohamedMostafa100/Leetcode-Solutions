class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int idx = queries[i][0];
            while(idx <= queries[i][1])
            {
                nums[idx] = ((long long)nums[idx] * queries[i][3]) % 1000000007;
                idx += queries[i][2];
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};