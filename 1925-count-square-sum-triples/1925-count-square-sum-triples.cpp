class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                double c = sqrt(pow(i, 2) + pow(j, 2));
                if(c == ceil(c) && c <= n)
                {
                    res += 2;
                }
            }
        }
        return res;
    }
};