class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> powers;
        int mask = 1;
        for(int i = 0; i < 32; i++)
        {
            if(n & mask)
            {
                powers.push_back(1 << i);
            }
            mask <<= 1;
        }
        for(int i = 0; i < queries.size(); i++)
        {
            long long prod = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                prod = (prod * powers[j]) % 1000000007;
            }
            res.push_back(prod);
        }
        return res;
    }
};