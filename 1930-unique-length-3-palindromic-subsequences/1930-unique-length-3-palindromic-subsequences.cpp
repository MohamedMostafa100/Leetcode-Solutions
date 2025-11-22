class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        unordered_set<char> chs;
        char toMatch = 'a';
        int first = -1;
        int last = -1;
        while(toMatch <= 'z')
        {
            int l = 0;
            int r = s.length() - 1;
            while(l <= r && (first == -1 || last == -1))
            {
                if(first == -1 && s[l] == toMatch)
                {
                    first = l;
                }
                else if(first == -1)
                {
                    l++;
                }
                if(last == -1 && s[r] == toMatch)
                {
                    last = r;
                }
                else if(last == -1)
                {
                    r--;
                }
            }
            for(int i = first + 1; i < last; i++)
            {
                chs.insert(s[i]);
            }
            res += chs.size();
            chs.clear();
            first = -1;
            last = -1;
            toMatch++;
        }
        return res;
    }
};