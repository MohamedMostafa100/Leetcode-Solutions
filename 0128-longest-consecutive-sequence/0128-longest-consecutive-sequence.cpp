class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        unordered_set<int> visited;
        for(auto n : numSet)
        {
            if(!visited.count(n))
            {
                visited.insert(n);
                int cur = n + 1;
                int count = 1;
                while(numSet.count(cur))
                {
                    count++;
                    visited.insert(cur);
                    cur++;
                }
                cur = n - 1;
                while(numSet.count(cur))
                {
                    count++;
                    visited.insert(cur);
                    cur--;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};