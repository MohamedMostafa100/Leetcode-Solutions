class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        for(int win = l; win <= r; win++)
        {
            int cur = 0;
            int s = 0;
            for(int e = 0; e < nums.size(); e++)
            {
                cur += nums[e];
                if(e - s + 1 == win)
                {
                    res = cur > 0 ? min(res, cur) : res;
                    cur -= nums[s];
                    s++;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};