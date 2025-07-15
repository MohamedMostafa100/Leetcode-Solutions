class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3)
        {
            return false;
        }
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        bool containsVowel = false;
        bool containsCon = false;
        for(int i = 0; i < word.length(); i++)
        {
            if((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))
            {
                if(vowels.find((1 << 5) | word[i]) != vowels.end())
                {
                    containsVowel = true;
                } 
                else
                {
                    containsCon = true;
                }
            }
            else if(word[i] >= '0' && word[i] <= '9')
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return containsVowel && containsCon;
    }
};