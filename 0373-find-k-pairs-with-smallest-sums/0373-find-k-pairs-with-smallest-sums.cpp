class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_set<string> visited;
        pq.push({nums1[0] + nums2[0], 0, 0});
        while(res.size() < k)
        {
            int val = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            string hash1 = to_string(i) + "," + to_string(j + 1);
            string hash2 = to_string(i + 1) + "," + to_string(j);
            if(j + 1 < nums2.size() && !visited.count(hash1))
            {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert(hash1);
            }
            if(i + 1 < nums1.size() && !visited.count(hash2))
            {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert(hash2);
            }
        } 
        return res;
    }
};