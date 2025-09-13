class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowel = 0;
        int maxConst = 0;
        int alpha[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            alpha[s[i] - 'a']++;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                maxVowel = max(maxVowel, alpha[s[i] - 'a']);
            }
            else
            {
                maxConst = max(maxConst, alpha[s[i] - 'a']);
            }
        }
        return maxVowel + maxConst;
    }
};