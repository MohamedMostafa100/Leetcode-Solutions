class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 1;
        unordered_set<int> rems;
        int lastRem = 1 % k;
        rems.insert(lastRem);
        while(lastRem != 0)
        {
            res++;
            int curRem = (((lastRem * 10) % k) + 1) % k;
            if(rems.find(curRem) != rems.end())
            {
                res = -1;
                break;
            }
            rems.insert(curRem);
            lastRem = curRem;
        }
        return res;
    }
};