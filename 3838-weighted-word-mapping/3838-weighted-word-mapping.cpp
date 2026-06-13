class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(int i = 0; i < words.size(); i++)
        {
            int score = 0;
            for(int j = 0; j < words[i].length(); j++)
            {
                score += weights[words[i][j] - 'a'];
            }
            res += ('z' - (score % 26));
        }
        return res;
    }
};