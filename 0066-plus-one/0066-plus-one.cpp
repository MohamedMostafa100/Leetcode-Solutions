class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        char carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] = (digits[i] + 1) % 10;
            carry = digits[i] == 0 ? 1 : 0;
            if(carry == 0)
            {
                return digits;
            }
        }
        digits.insert(digits.begin(), {1});
        return digits;
    }
};