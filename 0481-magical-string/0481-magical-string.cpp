class Solution {
public:
    int magicalString(int n) {
        if(n <= 3)
        {
            return 1;
        }
        int res = 1;
        string s = "122";
        bool ones = true;
        int l = 2;
        while(s.length() < n)
        {
            int length = s[l] - '0';
            if(ones)
            {
                s.append(length, '1');
                res += length;
                if(s.length() > n)
                {
                    res--;
                }
            }
            else
            {
                s.append(length, '2');
            }
            l++;
            ones = !ones;
        }
        return res;
    }
};