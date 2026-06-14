class Solution {
public:
    long long sumScores(string s) {
        long long res = 0;
        vector<int> lps(s.length(), 0);
        vector<int> counts;
        int i = 1;
        int l = 0;
        while(i < s.length())
        {
            if(s[i] == s[l])
            {
                l++;
                lps[i] = l;
                i++;
            }
            else if(l == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                l = lps[l - 1];
            }
        }
        for(int i = 0; i < lps.size(); i++)
        {
            cout << lps[i] << " "; 
            if(lps[i] > 0)
            {
                res += counts[lps[i] - 1] + 1;
                counts.push_back(counts[lps[i] - 1] + 1);
            }
            else
            {
                counts.push_back(0);
            }
        }
        return res + s.size();
    }
};