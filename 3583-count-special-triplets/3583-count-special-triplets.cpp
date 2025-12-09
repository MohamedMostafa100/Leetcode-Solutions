#define MOD 1000000007
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> freqs;
        unordered_map<int, int> leftFreqs;
        for(int i = 0; i < nums.size(); i++)
        {
            freqs[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            long long leftCount = leftFreqs.find(nums[i] * 2) != leftFreqs.end() ? leftFreqs[nums[i] * 2] : 0;
            leftFreqs[nums[i]]++;
            long long rightCount = freqs[nums[i] * 2] - leftFreqs[nums[i] * 2];
            res = (res + ((rightCount * leftCount) % MOD)) % MOD;
        }
        return res;
    }
};