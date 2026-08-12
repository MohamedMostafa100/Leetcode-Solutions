class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        int l = 0;
        unordered_map<int, int> freqs;
        for(int r = 0; r < n; r++)
        {
            freqs[nums[r]]++;
            while(freqs[nums[r]] > k)
            {
                freqs[nums[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};