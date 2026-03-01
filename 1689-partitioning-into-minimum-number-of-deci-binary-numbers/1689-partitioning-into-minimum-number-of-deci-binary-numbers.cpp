class Solution {
public:
    int minPartitions(string n) {
        char res = '1';
        for(int i = 0; i < n.length(); i++)
        {
            res = max(res, n[i]);
        }
        return res - '0';
    }
};