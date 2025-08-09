class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(ceil(log2(n)) == log2(n) && n != 0)
        {
            return true;
        }
        return false;
    }
};