class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        int hoursMask = 960;
        int minsMask = 63;
        for(int i = 1; i <= 1024; i++)
        {
            if(countBits(i) == turnedOn)
            {
                int h = (hoursMask & i) >> 6;
                int m = minsMask & i;
                if(h > 11 || m > 59)
                {
                    continue;
                }
                res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return res;
    }
private:
    char countBits(int n)
    {
        char bits = 0;
        int mask = 1;
        for(int i = 0; i < 10; i++)
        {
            if(mask & n)
            {
                bits++;
            }
            mask <<= 1;
        }
        return bits;
    }
};