class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        vector<int> freqs(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            freqs[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++)
        {
            freqs[s[i] - 'a']--;
            if(count(res.begin(), res.end(), s[i]))
            {
                continue;
            }
            while(res.length() > 0 && (s[i] < res[res.length() - 1] && freqs[res[res.length() - 1] - 'a'] > 0))
            {
                res.pop_back();
            }
            res += s[i];
        }
        return res;
    }
};