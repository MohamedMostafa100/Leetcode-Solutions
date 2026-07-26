class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            rank.assign(n, 0);
            for(int i = 0; i < n; i++)
            {
                parent.push_back(i);
            }
        }
        int find(int x)
        {
            if(parent[x] == x)
            {
                return x;
            }
            return find(parent[x]);
        }
        void unite(int x, int y)
        {
            int parX = find(x);
            int parY = find(y);
            if(parX == parY)
            {
                return;
            }
            if(rank[parX] > rank[parY])
            {
                parent[parY] = parX;
            }
            else if(rank[parX] < rank[parY])
            {
                parent[parX] = parY;
            }
            else
            {
                parent[parY] = parX;
                rank[parX]++;
            }
        }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> res;
        DSU dsu(n);
        for(int i = 0; i < requests.size(); i++)
        {
            DSU temp = dsu;
            bool valid = true;
            temp.unite(requests[i][0], requests[i][1]);
            for(int j = 0; j < restrictions.size(); j++)
            {
                if(temp.find(restrictions[j][0]) == temp.find(restrictions[j][1]))
                {
                    valid = false;
                    res.push_back(false);
                    break;
                }
            }
            if(valid)
            {
                res.push_back(true);
                dsu = temp;
            }
        }
        return res;
    }
};