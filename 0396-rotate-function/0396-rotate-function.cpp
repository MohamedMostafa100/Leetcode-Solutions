class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int last = 0;
        int tot = 0;
        for(int i = 0; i < n; i++)
        {
            last += (i * nums[i]);
            tot += nums[i];
        }
        res = last;
        for(int i = 0; i < n - 1; i++)
        {
            last += tot - n * nums[n - i - 1];
            res = max(res, last);
        }
        return res;
    }
};