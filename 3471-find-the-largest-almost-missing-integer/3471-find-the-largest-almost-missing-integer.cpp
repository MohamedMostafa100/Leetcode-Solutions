class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)
        {
            int mx = 0;
            for(int i = 0; i < n; i++)
            {
                mx = max(mx, nums[i]);
            }
            return mx;
        }  
        int res = -1;
        unordered_map<int, int> freqs;
        for(int i = 0; i < n; i++)
        {
            freqs[nums[i]]++;
        }
        if(k == 1)
        {
            for(auto& [x, f] : freqs)
            {
                if(f == 1)
                {
                    res = max(res, x);
                }
            }
        }
        else
        {
            if(freqs[nums[0]] == 1)
            {
                res = max(res, nums[0]);
            }
            if(freqs[nums[n - 1]] == 1)
            {
                res = max(res, nums[n - 1]);
            }
        }
        return res;
    }
};