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
        }
        for(int i = k - 1; i < nums.size(); i++)
        {
            long long prev = 0;
            if(i - k >= k - 1)
            {
                prev = pre[i - k];
            }
            res = max(res, pre[i] + prev);
            if(pre[i] + prev < 0)
            {
                pre[i] = 0;
            }
            else
            {
                pre[i] += prev;
            }
        }
        return res;
    }
};