class Solution {
public:
    int minFlips(string s) {
        int res = 0;
        vector<vector<int>> freqs(2, vector<int>(2, 0));
        for(int i = 0; i < s.length(); i++)
        {
            if(i % 2 == 0)
            {
                freqs[0][s[i] - '0']++;
            }
            else
            {
                freqs[1][s[i] - '0']++;
            }
        }
        if(s.length() % 2 == 0)
        {
            return s.length() - max(freqs[0][0] + freqs[1][1], freqs[0][1] + freqs[1][0]);
        }
        for(int i = 0; i < s.length(); i++)
        {
            swap(freqs[0][0], freqs[1][0]);
            swap(freqs[0][1], freqs[1][1]);
            if(s[i] == '0')
            {
                freqs[0][0]++;
                freqs[1][0]--;
            }
            else
            {
                freqs[0][1]++;
                freqs[1][1]--;
            }
            res = max(res, max(freqs[0][0] + freqs[1][1], freqs[0][1] + freqs[1][0]));
        }
        return s.length() - res;
    }
};