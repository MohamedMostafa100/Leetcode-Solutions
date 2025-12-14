#define MOD 1000000007
class Solution {
public:
    int numberOfWays(string corridor) {
        int res = 1;
        vector<int> segments;
        int pair = 0;
        int poss = 0;
        for(int i = 0; i < corridor.length(); i++)
        {
            if(corridor[i] == 'S')
            {
                if(pair == 2)
                {
                    segments.push_back(poss);
                    pair = 0;
                    poss = 0;
                }
                pair++;
            }
            if(pair == 2)
            {
                poss++;
            }
        }
        if(pair == 1 || pair == 0)
        {
            return 0;
        }
        segments.push_back(1);
        for(int i = 0; i < segments.size(); i++)
        {
            res = (res * 1LL * segments[i]) % MOD;
        }
        return res;
    }
};