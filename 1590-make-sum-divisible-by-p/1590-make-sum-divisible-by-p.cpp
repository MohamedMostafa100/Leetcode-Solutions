class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int res = n;
        unordered_map<int, stack<int>> mp;
        int rem = 0;
        for(int i = 0; i < n; i++)
        {
            rem = (rem + nums[i]) % p;
            mp[rem].push(i);
            if(rem == 0)
            {
                res = min(res, n - i - 1);
                if(res == 0)
                {
                    return 0;
                }
            }
        }
        rem = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            rem = (rem + nums[i]) % p;
            if(rem == 0)
            {
                res = min(res, i);
            }
            if(mp.find((p - rem) % p) != mp.end())
            {
                while(!mp[(p - rem) % p].empty() && i <= mp[(p - rem) % p].top())
                {
                    mp[(p - rem) % p].pop();
                }
                if(!mp[(p - rem) % p].empty())
                {
                    res = min(res, i - mp[(p - rem) % p].top() - 1);
                }
            }
        }
        if(res == n)
        {
            return -1;
        }
        return res;
    }
};