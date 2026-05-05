class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
        {
            return false;
        }
        vector<int> lps = kmp(goal);
        s += s;
        int i = 0;
        int j = 0;
        while(i < s.length())
        {
            if(s[i] == goal[j])
            {
                i++;
                j++;
                if(j == goal.size())
                {
                    return true;
                }
            }
            else
            {
                if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return false;
    }
private:
    vector<int> kmp(string pat)
    {
        vector<int> lps;
        lps.push_back(0);
        int l = 0;
        for(int i = 1; i < pat.length(); i++)
        {
            if(pat[i] == pat[l])
            {
                l++;
                lps.push_back(l);
            }
            else
            {
                if(pat[i] == pat[lps[max(l - 1, 0)]])
                {
                    l = lps[max(l - 1, 0)] + 1;
                }
                else
                {
                    l = 0;
                }
                lps.push_back(l);
            }
        }
        return lps;
    }
};