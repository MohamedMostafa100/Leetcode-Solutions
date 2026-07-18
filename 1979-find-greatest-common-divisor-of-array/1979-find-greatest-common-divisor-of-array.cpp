class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = 0;
        int mn = 1000;
        for(int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        return gcd(mn, mx);
    }
};