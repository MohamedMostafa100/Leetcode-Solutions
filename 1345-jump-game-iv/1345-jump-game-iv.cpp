class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        unordered_map<int, vector<int>> idxs;
        vector<bool> visited(n, false);
        queue<pair<int, int>> bfs;
        for(int i = 0; i < n; i++)
        {
            idxs[arr[i]].push_back(i);
        }
        bfs.push({0, 0});
        while(!bfs.empty())
        {
            int node = bfs.front().first;
            int dist = bfs.front().second;
            bfs.pop();
            if(node == n - 1)
            {
                res = dist;
                break;
            }    
            visited[node] = true;
            for(int i = 0; i < idxs[arr[node]].size(); i++)
            {
                if(!visited[idxs[arr[node]][i]])
                {
                    bfs.push({idxs[arr[node]][i], dist + 1});
                }
            }
            idxs[arr[node]].clear();
            if(node > 0 && !visited[node - 1])
            {
                bfs.push({node - 1, dist + 1});
            }
            if(node < n - 1 && !visited[node + 1])
            {
                bfs.push({node + 1, dist + 1});
            }
        }
        return res;
    }
};