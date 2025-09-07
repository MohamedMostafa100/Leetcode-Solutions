class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            res += numOperations(queries[i][0], queries[i][1]);
        }
        return res;
    }
private:
    long long numOperations(int s, int e)
    {
        char pow = 1;
        int base = 4;
        int last = s;
        long long ops = 0;
        while(base <= e)
        {
            if(base > last)
            {
                ops += ((long long)base - last) * pow;
                last = base;
            }
            base <<= 2;
            pow++;
        }
        ops += ((long long)e - last + 1) * pow;
        return ceil((double)ops / 2);
    }
};