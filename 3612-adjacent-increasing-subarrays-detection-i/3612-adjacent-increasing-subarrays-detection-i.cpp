class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1)
        {
            return true;
        }
        unordered_set<int> incSubs;
        int l = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                if(i - l + 1 == k)
                {
                    if(incSubs.find(l - k) != incSubs.end())
                    {
                        return true;
                    }
                    incSubs.insert(l);
                    l++;
                }
            }
            else
            {
                l = i;
            }
        }
        return false;
    }
};