class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        return n * mx - sum;
    }
};