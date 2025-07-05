class Solution {
public:
    char kthCharacter(int k) {
        char res = 'a';
        int steps = 0;
        while (k > 1) {
            k -= pow(2, floor(log2(k - 1)));
            steps++;
        }
        return res + steps;
    }
};