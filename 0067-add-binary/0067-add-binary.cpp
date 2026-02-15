class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        char carry = 0;
        while(i >= 0 || j >= 0)
        {
            char x = 0;
            char y = 0;
            if(i >= 0)
            {
                x = a[i] - '0';
                i--;
            }
            if(j >= 0)
            {
                y = b[j] - '0';
                j--;
            }
            res = to_string(x ^ y ^ carry) + res;
            carry = (x + y + carry) / 2;
        }
        if(carry == 1)
        {
            res = "1" + res;
        }
        return res;
    }
};