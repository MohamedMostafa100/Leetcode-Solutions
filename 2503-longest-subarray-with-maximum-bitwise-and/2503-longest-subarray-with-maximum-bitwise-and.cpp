class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        unsigned int andSum = ~(0);
        int maxAnd = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if ((andSum & nums[r]) < andSum || nums[r] > andSum) {
                l = r;
                andSum = ~(0);
            }
            andSum &= nums[r];
            if (andSum > maxAnd) {
                maxAnd = andSum;
                res = r - l + 1;
            }
            else if(andSum == maxAnd)
            {
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};