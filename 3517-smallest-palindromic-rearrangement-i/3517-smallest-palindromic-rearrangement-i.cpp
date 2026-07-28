class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string res(n, 'a');
        vector<int> alpha(26, 0);
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            alpha[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            int freq = alpha[i];
            if(freq > 0)
            {
                for(int j = 0; j < alpha[i] / 2; j++)
                {
                    res[idx] = 'a' + i;
                    res[n - idx - 1] = 'a' + i;
                    freq -= 2;
                    idx++;
                }
                if(freq == 1)
                {
                    res[n / 2] = 'a' + i;
                }
            }
        }
        return res;
    }
};