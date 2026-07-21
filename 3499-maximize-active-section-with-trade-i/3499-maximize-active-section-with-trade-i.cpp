class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int res = 0;
        int prev = 0;
        int cur = 0;
        int seqCount = 0;
        int maxLength = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                res++;
            }
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                seqCount++;
                while(s[i] == '0')
                {
                    cur++;
                    i++;
                }
                if(seqCount >= 2)
                {
                    maxLength = max(maxLength, cur + prev);
                }
                prev = cur;
                cur = 0;
            }
        }
        if(seqCount >= 2)
        {
            maxLength = max(maxLength, cur + prev);
        }
        res += maxLength;
        return res;
    }
};