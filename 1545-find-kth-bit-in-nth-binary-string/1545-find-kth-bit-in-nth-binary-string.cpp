class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)
        {
            return '0';
        }
        int length = (1 << n) - 1;
        if(k - 1 == length / 2)
        {
            return '1';
        }
        else if(k - 1 < length / 2)
        {
            return findKthBit(n - 1, k);
        }
        return findKthBit(n - 1, length - k + 1) == '1' ? '0' : '1';
    }
};