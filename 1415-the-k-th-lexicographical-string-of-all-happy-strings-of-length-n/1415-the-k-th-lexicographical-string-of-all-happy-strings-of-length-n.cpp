class Solution {
public:
    string getHappyString(int n, int k) {
        if(k > 3 * (1 << (n - 1)))
        {
            return "";
        }
        string res = "";
        char last = '0';
        k--;
        while(n > 0)
        {
            int idx = k / (1 << (n - 1));
            last = nextChar(last, idx);
            res += last;
            k %= (1 << (n - 1));
            n--;
        }
        return res;
    }
private:
    char nextChar(char cur, int idx)
    {
        if(cur == '0')
        {
            if(idx == 0)
            {
                return 'a';
            }
            else if(idx == 1)
            {
                return 'b';
            }
            return 'c';
        }
        if(cur == 'a')
        {
            if(idx == 0)
            {
                return 'b';
            }
            return 'c';
        }
        if(cur == 'b')
        {
            if(idx == 0)
            {
                return 'a';
            }
            return 'c';
        }
        else
        {
            if(idx == 0)
            {
                return 'a';
            }
            return 'b';
        }
        return '0';
    }
};