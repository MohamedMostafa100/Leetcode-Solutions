class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd;
        for(int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd.push_back(gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        for(int i = 0; i < n / 2; i++)
        {
            res += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }
        return res;
    }
};