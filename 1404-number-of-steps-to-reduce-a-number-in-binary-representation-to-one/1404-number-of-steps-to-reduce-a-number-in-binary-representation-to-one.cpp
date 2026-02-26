class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        string one(s.length(), '0');
        one[s.length() - 1] = '1';
        while(s != one)
        {
            if(s[s.length() - 1] == '1')
            {
                inc(s, one);
            }
            else
            {
                divide(s);
            }
            res++;
        }
        return res;
    }
private:
    void divide(string& s)
    {
        s = "0" + s;
        s.pop_back();
    }
    void inc(string& s, string& one)
    {
        int i = s.length() - 1;
        while(i >= 0 && s[i] == '1')
        {
            s[i] = '0';
            i--;
        }
        if(i >= 0)
        {
            s[i] = '1';
        }
        else
        {
            s = "1" + s;
            one = "0" + one;
        }
    }
};