class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        bool stationary = false;
        for(int i = 0; i < directions.size(); i++)
        {
            if(directions[i] == 'R')
            {
                int count = 0;
                while(i < directions.size() && directions[i] == 'R')
                {
                    count++;
                    i++;
                }
                if(i < directions.size())
                {
                    if(directions[i] == 'S')
                    {
                        res += count;
                    }
                    else
                    {
                        res += count + 1;
                    }
                    stationary = true;
                }
            }
            else if(directions[i] == 'S')
            {
                stationary = true;
            }
            else
            {
                if(stationary)
                {
                    res++;
                }
            }
        }
        return res;
    }
};