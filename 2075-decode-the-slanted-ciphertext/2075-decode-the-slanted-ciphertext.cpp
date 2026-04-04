class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res = "";
        int cols = encodedText.length() / rows;
        for(int idx = 0; idx < cols; idx++)
        {
            int i = 0;
            int j = idx;
            while(i < rows && j < cols)
            {
                res += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
        while(!res.empty() && res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};