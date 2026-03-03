class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for(int i = 1; i < n; i++)
        {
            string add = invert(s);
            reverse(add.begin(), add.end());
            s = s + '1' + add;
        }
        return s[k - 1];
    }
private:
    string invert(string& s)
    {
        string res = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                res += '1';
            }
            else
            {
                res += '0';
            }
        }
        return res;
    }
};