class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long res = 0;
        sort(nums.begin(), nums.end());

        vector<int> powers(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
        {
            powers[i] = (2 * powers[i - 1]) % 1000000007;
        }

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (nums[i] + nums[j] <= target) {
                res = (res + powers[j - i]) % 1000000007;
                i++;
            } else {
                j--;
            }
        }

        if (nums[i] * 2 <= target) {
            res++;
        }

        return res;
    }
};