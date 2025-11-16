class Solution {
public:
    int numSub(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            long long n = 0;
            while(i < s.length() && s[i] == '1')
            {
                n++;
                i++;
            }
            res += ((n * (n + 1) / 2) % 1000000007);
        }
        return res;
    }
};