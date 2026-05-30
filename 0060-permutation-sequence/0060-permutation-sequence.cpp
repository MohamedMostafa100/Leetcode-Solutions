class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        int fact = 1;
        for(int i = 2; i < n; i++)
        {
            fact *= i;
        }
        vector<int> used;
        for(int i = 1; i <= n; i++)
        {
            used.push_back(i);
        }
        int start = 1;
        for(int i = 1; i < n; i++)
        {
            int idx = (k - start) / fact;
            res += to_string(used[idx]);
            used.erase(used.begin() + idx);
            start += fact * idx;
            fact /= (n - i);
        }
        res += to_string(used[0]);
        return res;
    }
};