class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        vector<long long> pre(nums.size(), 0);
        int l = 0;
        long long sum = 0;
        for(int r = 0; r < nums.size(); r++)
        { 
            sum += (long long)nums[r];
            if(r - l + 1 < k)
            {
                pre[r] = nums[r];
            }
            else
            {
                pre[r] = sum;
                sum -= (long long)nums[l];
                l++;
            }
            if(r >= k - 1)
            {
                long long prev = 0;
                if(r - k >= k - 1)
                {
                    prev = pre[r - k];
                }
                res = max(res, pre[r] + prev);
                if(pre[r] + prev < 0)
                {
                    pre[r] = 0;
                }
                else
                {
                    pre[r] += prev;
                }
            }
        }
        return res;
    }
};