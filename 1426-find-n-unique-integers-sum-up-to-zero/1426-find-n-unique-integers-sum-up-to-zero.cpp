class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        short s = 1;
        while(res.size() < n - 1)
        {
            res.push_back(s);
            res.push_back(-s);
            s++;
        }
        if(res.size() < n)
        {
            res.push_back(0);
        }
        return res;
    }
};