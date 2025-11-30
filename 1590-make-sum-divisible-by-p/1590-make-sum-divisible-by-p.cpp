class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int res = n;
        unordered_map<int, int> mp;
        int totRem = 0;
        for(int i = 0; i < n; i++)
        {
            totRem = (totRem + nums[i]) % p;
            if(totRem == 0)
            {
                res = min(res, n - i - 1);
                if(res == 0)
                {
                    return 0;
                }
            }
        }
        int rem = 0;
        for(int i = 0; i < n; i++)
        {
            int sufRem = (totRem - rem) % p;
            if(mp.find((p - sufRem) % p) != mp.end())
            {
                res = min(res, i - mp[(p - sufRem) % p] - 1);
            }
            rem = (rem + nums[i]) % p;
            mp[rem] = i;
            if(sufRem == 0)
            {
                res = min(res, i);
            }
        }
        if(res == n)
        {
            return -1;
        }
        return res;
    }
};