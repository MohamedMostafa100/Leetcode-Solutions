class Solution {
public:
    int numberOfSpecialChars(string s) {
        int res = 0;
        unordered_set<char> found;
        for(int i = 0; i < s.length(); i++)
        {
            if(!found.count(s[i]))
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    if(found.count(s[i] - 32))
                    {
                        res++;
                    }
                    found.insert(s[i]);
                }
                else
                {
                    if(found.count(s[i] + 32))
                    {
                        res++;
                    }
                    found.insert(s[i]);
                }
            }
        }
        return res;
    }
};