class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(s, res, "", 0, 0);
        return res;
    }
private:
    void solve(string s, vector<string>& res, string cur, int start, int dots)
    {
        if(start == s.length())
        {
            return;
        }
        if(dots == 3)
        {
            string rem = s.substr(start, s.length() - start);
            if(rem.length() > 3 || stoi(rem) > 255 || (rem.length() > 1 && s[start] == '0'))
            {
                return;
            }
            cur += rem;
            res.push_back(cur);
            return;
        }
        for(int i = start; i < min(start + 3, (int)s.length()); i++)
        {
            string subnet = s.substr(start, i - start + 1);
            if(stoi(subnet) > 255 || (subnet.length() > 1 && s[start] == '0'))
            {
                return;
            }
            solve(s, res, cur + subnet + ".", i + 1, dots + 1);
        }
    }
};