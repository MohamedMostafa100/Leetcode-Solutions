class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, vector<int>> idxs;
        unordered_map<int, int> idxDists;
        for (int i = 0; i < n; i++) {
            idxs[nums[i]].push_back(i);
        }
        for (auto& [num, idx] : idxs) {
            int m = idx.size();
            if (m > 1) {
                for (int i = 0; i < m; i++) {
                    if (i == 0) {
                        idxDists[idx[i]] = min(idx[1] - idx[0], n - idx[m-1] + idx[0]);
                    } else if (i == m - 1) {
                        idxDists[idx[i]] = min(idx[m-1] - idx[m-2], n - idx[m-1] + idx[0]);
                    } else {
                        idxDists[idx[i]] = min(idx[i] - idx[i-1], idx[i+1] - idx[i]);
                    }
                }
            }
        }
        for (int q : queries) {
            if (idxDists.count(q)) {
                res.push_back(idxDists[q]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};