class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        int repeated = 0;
        unordered_map<int, int> freqs;
        for(int i = 0; i < nums.size(); i++)
        {
            freqs[nums[i]]++;
            if(freqs[nums[i]] > maxFreq)
            {
                maxFreq = freqs[nums[i]];
                repeated = 1;
            }
            else if(freqs[nums[i]] == maxFreq)
            {
                repeated++;
            }
        }
        return maxFreq * repeated;
    }
};