class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int smallCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                smallCount++;
            }
        }
        if(smallCount == 0 || smallCount == n || (smallCount == n - 1 && word[0] >= 'A' && word[0] <= 'Z'))
        {
            return true;
        }
        return false;
    }
};