class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> res;
        unordered_map<int, pair<int, int>> idxPre;
        unordered_map<int, pair<int, int>> idxSuf;
        vector<long long> pre(arr.size(), 0);
        vector<long long> suf(arr.size(), 0);
        for (int i = 0; i < arr.size(); ++i) {
            if (idxPre.count(arr[i])) {
                pre[i] = pre[idxPre[arr[i]].first] + ((long long)(i - idxPre[arr[i]].first) * idxPre[arr[i]].second);
                idxPre[arr[i]] = {i, idxPre[arr[i]].second + 1};
            } else {
                idxPre[arr[i]] = {i, 1};
            }
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (idxSuf.count(arr[i])) {
                suf[i] = suf[idxSuf[arr[i]].first] + ((long long)(idxSuf[arr[i]].first - i) * idxSuf[arr[i]].second);
                idxSuf[arr[i]] = {i, idxSuf[arr[i]].second + 1};
            } else {
                idxSuf[arr[i]] = {i, 1};
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            res.push_back(pre[i] + suf[i]);
        }
        return res;
    }
};