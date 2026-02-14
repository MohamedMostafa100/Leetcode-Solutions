class Solution {
public:
    int longestBalanced(string s) {
        int res = 0;
        res = max(res, case1(s, 'a'));
        res = max(res, case1(s, 'b'));
        res = max(res, case1(s, 'c'));
        res = max(res, case2(s, 'a', 'b'));
        res = max(res, case2(s, 'a', 'c'));
        res = max(res, case2(s, 'b', 'c'));
        res = max(res, case3(s));
        return res;
    }
private:
    int case1(string s, char x)
    {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int cnt = 0;
            while(i < s.length() && s[i] == x)
            {
                cnt++;
                res = max(res, cnt);
                i++;
            }
        }
        return res;
    }
    int case2(string s, char x, char y)
    {
        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            unordered_map<int, int> diff;
            diff[0] = i - 1;
            int xCnt = 0;
            int yCnt = 0;
            while(i < s.length() && (s[i] == x || s[i] == y))
            {
                if(s[i] == x)
                {
                    xCnt++;
                }
                else
                {
                    yCnt++;
                }
                int curDiff = xCnt - yCnt;
                if(diff.count(curDiff))
                {
                    res = max(res, i - diff[curDiff]);
                }
                else
                {
                    diff[curDiff] = i;
                }    
                i++;
            }
        }
        return res;
    }
    int case3(string s)
    {
        int res = 0;
        unordered_map<string, int> diff;
        int a = 0;
        int b = 0;
        int c = 0;
        int d1 = 0;
        int d2 = 0;
        diff["0,0"] = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                a++;
            }
            else if(s[i] == 'b')
            {
                b++;
            }
            else
            {
                c++;
            }
            d1 = a - b;
            d2 = a - c;
            string hash = to_string(d1) + "," + to_string(d2);
            if(diff.count(hash))
            {
                res = max(res, i - diff[hash]);
            }
            else
            {
                diff[hash] = i;
            }
        }
        return res;
    }
};