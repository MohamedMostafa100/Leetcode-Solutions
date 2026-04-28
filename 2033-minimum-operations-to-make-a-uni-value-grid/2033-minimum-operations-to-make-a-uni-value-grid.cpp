class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int flatLen = m * n; 
        int res = 0;
        int last = grid[0][0];
        vector<int> nums;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(abs(grid[i][j] - last) % x != 0)
                {
                    return -1;
                }
                last = grid[i][j];
                nums.push_back(last);
            }
        }
        sort(nums.begin(), nums.end());
        int mid = nums[flatLen / 2];
        for(int i = 0; i < flatLen; i++)
        {
            res += abs(nums[i] - mid) / x;
        }
        return res;
    }
};