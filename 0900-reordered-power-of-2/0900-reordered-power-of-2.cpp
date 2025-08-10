class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for(unsigned int i = 1; i < (1ul << 31) - 1; i <<= 1)
        {
            string cmp = to_string(i);
            sort(cmp.begin(), cmp.end());
            if(cmp == s)
            {
                return true;
            }
        }
        return false;
    }
};