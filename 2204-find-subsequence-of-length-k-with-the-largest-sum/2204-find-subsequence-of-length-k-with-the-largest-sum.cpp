class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        unordered_set<int> idxs;

        for(int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        for(int i = 0; i < k; i++)
        {
            idxs.insert(pq.top().second);
            pq.pop();
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(idxs.find(i) != idxs.end())
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};