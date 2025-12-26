class Solution {
public:
    int bestClosingTime(string customers) {
        int res = 0;
        int pen = 0;
        int y = 0;
        int n = 0;
        int yCur = 0;
        int nCur = 0;
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i] == 'Y')
            {
                y++;
            }
            else
            {
                n++;
            }
        }
        pen = y;
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i] == 'Y')
            {
                yCur++;
            }
            else
            {
                nCur++;
            }
            if((nCur + y - yCur) < pen)
            {
                pen = nCur + y - yCur;
                res = i + 1;
            }
        }
        return res;
    }
};