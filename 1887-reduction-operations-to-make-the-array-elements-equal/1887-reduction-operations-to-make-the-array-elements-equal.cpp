class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] != nums[i + 1])
            {
                res += n - i - 1;
            }
        }
        return res;
    }
};