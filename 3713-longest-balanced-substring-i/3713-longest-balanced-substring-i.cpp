class Solution {
public:
    int longestBalanced(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            unordered_map<char, int> freqs;
            int maxNum = 0;
            int maxs = 0;
            for(int j = i; j < s.length(); j++)
            {
                freqs[s[j]]++;
                if(freqs[s[j]] > maxNum)
                {
                    maxNum = freqs[s[j]];
                    maxs = 1;
                }
                else if(freqs[s[j]] == maxNum)
                {
                    maxs++;
                }
                if(maxs == freqs.size())
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};