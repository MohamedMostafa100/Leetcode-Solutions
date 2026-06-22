class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        string cond = "balon";
        unordered_map<char, int> freqs;
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n')
            {
                freqs[text[i]]++;
            }
        }
        for(int i = 0; i < cond.length(); i++)
        {
            if(!freqs.count(cond[i]))
            {
                return 0;
            }
            if(cond[i] == 'l' || cond[i] == 'o')
            {
                res = min(res, freqs[cond[i]] / 2);
            }
            else
            {
                res = min(res, freqs[cond[i]]);
            }
        }
        return res;
    }
};