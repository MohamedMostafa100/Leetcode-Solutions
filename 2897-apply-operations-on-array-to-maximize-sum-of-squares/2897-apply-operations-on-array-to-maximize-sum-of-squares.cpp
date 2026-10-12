class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int res = 0;
        int mod = 1000000007;
        vector<int> bitCount(31, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            int mask = 1;
            for(int j = 0; j < 31; j++)
            {
                if(nums[i] & mask)
                {
                    bitCount[j]++;
                }
                mask <<= 1;
            }
        }
        for(int i = 0; i < k; i++)
        {
            long long cur = 0;
            for(int j = 0; j < 31; j++)
            {
                if(bitCount[j] > 0)
                {
                    cur += (1 << j);
                    bitCount[j]--;
                }
            }
            res = (res + (cur * cur) % mod) % mod;
        }
        return res;
    }
};