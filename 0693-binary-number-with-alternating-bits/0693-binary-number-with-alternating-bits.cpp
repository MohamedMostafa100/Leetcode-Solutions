class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = (n >> 1) ^ n;
        if((x & (x + 1)) == 0)
        {
            return true;
        }
        return false;
    }
};