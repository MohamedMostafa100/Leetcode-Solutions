class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        char res = 'a';
        int steps = 0;
        while (k > 1) {
            if(operations[floor(log2(k - 1))] == 1)
            {
                steps++;
            }
            k -= pow(2, floor(log2(k - 1)));
        }
        return res + (steps % 26);
    }
};