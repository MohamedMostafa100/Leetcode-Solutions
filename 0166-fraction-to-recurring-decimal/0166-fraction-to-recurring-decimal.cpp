class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        string fraction = "";
        unordered_map<int, unordered_map<int, int>> remPos;
        int pos = 0;
        long long num = numerator;
        long long den = denominator;
        if(num == 0)
        {
            return "0";
        }
        if(num < 0 && den < 0)
        {
            num *= -1;
            den *= -1;
        }
        else if(num < 0)
        {
            res += '-';
            num *= -1;
        }
        else if(den < 0)
        {
            res += '-';
            den *= -1;
        }
        res += to_string(num / den);
        num %= den;
        num *= 10;
        while (num > 0) {
            int cur = num / den;
            int rem = num % den;
            if (remPos.find(cur) != remPos.end()) {
                if(remPos[cur].find(rem) != remPos[cur].end())
                {
                    fraction = fraction.substr(0, remPos[cur][rem]) + "(" +
                           fraction.substr(remPos[cur][rem],
                                           fraction.length() - remPos[cur][rem]) +
                           ")";
                    break;
                }
            } 
            fraction += ('0' + cur);
            remPos[cur][rem] = pos;
            pos++;
            num = rem;
            num *= 10;
        }
        if (!fraction.empty()) {
            res += "." + fraction;
        }
        return res;
    }
};