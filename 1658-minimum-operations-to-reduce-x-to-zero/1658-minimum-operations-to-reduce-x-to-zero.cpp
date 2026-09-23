class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = INT_MAX;
        int n = nums.size();
        int preSum = 0;
        int sufSum = 0;
        unordered_map<int, int> pre;
        unordered_map<int, int> suf;
        for(int i = 0; i < n; i++)
        {
            preSum += nums[i];
            sufSum += nums[n - i - 1];
            pre[preSum] = i;
            suf[sufSum] = n - i - 1;
            if(preSum == x)
            {
                res = min(res, i + 1);
            }
            if(sufSum == x)
            {
                res = min(res, i + 1);
            }
            if(suf.count(x - preSum) && i < suf[x - preSum])
            {
                res = min(res, i + 1 + n - suf[x - preSum]);
            }
            if(pre.count(x - sufSum) && n - i - 1 > pre[x - sufSum])
            {
                res = min(res, i + 1 + pre[x - sufSum] + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};