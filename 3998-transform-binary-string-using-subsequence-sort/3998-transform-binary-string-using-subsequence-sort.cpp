class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> res;
        int n = s.length();
        int z = 0;
        vector<int> zeros;
        int curSuf = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                z++;
                zeros.push_back(i);
            }
        }
        for (int i = 0; i < strs.size(); i++) {
            int curZ = 0;
            vector<int> curZeros;
            for(int j = 0; j < n; j++)
            {
                if(strs[i][j] == '0')
                {
                    curZ++;
                }
            }
            for(int j = 0; j < n; j++)
            {
                if(strs[i][j] == '0')
                {
                    curZeros.push_back(j);
                }
                else if(strs[i][j] == '?')
                {
                    if(curZ < z)
                    {
                        curZ++;
                        curZeros.push_back(j);
                    }
                }
            }
            if(z != curZ)
            {
                res.push_back(false);
                continue;
            }
            bool transformable = true;
            for(int j = 0; j < zeros.size(); j++)
            {
                if(zeros[j] < curZeros[j])
                {
                    transformable = false;
                    res.push_back(false);
                    break;
                }
            }
            if(transformable)
            {
                res.push_back(true);
            }
        }
        return res;
    }
};