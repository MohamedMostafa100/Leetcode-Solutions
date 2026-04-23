class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res;
        unordered_map<int, pair<int, int>> idxPre;
        unordered_map<int, pair<int, int>> idxSuf;
        vector<long long> pre(nums.size(), 0);
        vector<long long> suf(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (idxPre.count(nums[i])) {
                pre[i] = pre[idxPre[nums[i]].first] + ((long long)(i - idxPre[nums[i]].first) * idxPre[nums[i]].second);
                idxPre[nums[i]] = {i, idxPre[nums[i]].second + 1};
            } else {
                idxPre[nums[i]] = {i, 1};
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (idxSuf.count(nums[i])) {
                suf[i] = suf[idxSuf[nums[i]].first] + ((long long)(idxSuf[nums[i]].first - i) * idxSuf[nums[i]].second);
                idxSuf[nums[i]] = {i, idxSuf[nums[i]].second + 1};
            } else {
                idxSuf[nums[i]] = {i, 1};
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            res.push_back(pre[i] + suf[i]);
        }
        return res;
    }
};