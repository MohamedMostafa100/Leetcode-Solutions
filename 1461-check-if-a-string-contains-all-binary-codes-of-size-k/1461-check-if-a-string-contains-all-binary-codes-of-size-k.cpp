class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int possible = (1 << k);
        int verified = 0;
        vector<bool> checked(possible, false);
        for(int i = 0; i < n - k + 1; i++)
        {
            int idx = binToInt(s.substr(i, k));
            if(!checked[idx])
            {
                checked[idx] = true;
                verified++;
            }
        }
        if(verified == possible)
        {
            return true;
        }
        return false;
    }
private:
    int binToInt(string bin)
    {
        int n = bin.length();
        int res = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(bin[i] == '1')
            {
                res += (1 << (bin.length() - i - 1));
            }
        }
        return res;
    }
};