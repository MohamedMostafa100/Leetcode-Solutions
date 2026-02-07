class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int n = s.length();
        int a = 0;
        vector<int> suffB(n, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == 'b')
            {
                suffB[i]++;
            }
            if(i < n - 1)
            {
                suffB[i] += suffB[i + 1];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                a++;
            }
            res = max(res, a + suffB[i]);
        }
        return n - res;
    }
};