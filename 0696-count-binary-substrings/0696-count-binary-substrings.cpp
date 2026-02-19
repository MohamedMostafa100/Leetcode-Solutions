class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int first = 0;
        int second = 1;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i - 1])
            {
                second++;
            }
            else
            {
                res += min(first, second);
                first = second;
                second = 1;
            }
        }
        return res + min(first, second);
    }
};