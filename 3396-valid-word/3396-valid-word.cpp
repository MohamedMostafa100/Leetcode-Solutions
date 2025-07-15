class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3)
        {
            return false;
        }
        bool containsVowel = false;
        bool containsCon = false;
        for(int i = 0; i < word.length(); i++)
        {
            if(isalpha(word[i]))
            {
                char lowercase = (1 << 5) | word[i];
                if(lowercase == 'a' || lowercase == 'e' || lowercase == 'i' || lowercase == 'o' || lowercase == 'u')
                {
                    containsVowel = true;
                } 
                else
                {
                    containsCon = true;
                }
            }
            else
            {
                if(!isdigit(word[i]))
                {
                    return false;
                }            
            }
        }

        return containsVowel && containsCon;
    }
};