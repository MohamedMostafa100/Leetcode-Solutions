class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(const auto& num : nums)
        {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        return 1LL * (maxNum - minNum) * k;
    }
};