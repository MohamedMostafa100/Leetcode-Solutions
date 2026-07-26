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
    int largestComponentSize(vector<int>& nums) {
        int res = 0;
        DSU dsu(nums.size());
        unordered_map<int, int> factors;
        vector<int> counts(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            for(int j = 2; j <= sqrt(x); j++)
            {
                if(x % j == 0)
                {
                    if(factors.count(j))
                    {
                        dsu.unite(i, factors[j]);
                    }
                    else
                    {
                        factors[j] = i;
                    }
                    while(x % j == 0)
                    {
                        x /= j;
                    }
                }
            }
            if(x > 1)
            {
                if(factors.count(x))
                {
                    dsu.unite(i, factors[x]);
                }
                else
                {
                    factors[x] = i;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int x = dsu.find(i);
            counts[x]++;
            res = max(res, counts[x]);
        }
        return res;
    }
};