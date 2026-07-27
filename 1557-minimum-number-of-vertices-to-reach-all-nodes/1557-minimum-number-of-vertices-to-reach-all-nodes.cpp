class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<bool> reachable(n, false);
        for(int i = 0; i < edges.size(); i++)
        {
            reachable[edges[i][1]] = true;
        }
        for(int i = 0; i < n; i++)
        {
            if(!reachable[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};