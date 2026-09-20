class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xNearest = 0;
        int yNearest = 0;
        float dist = 0;
        if(xCenter >= x1 && xCenter <= x2)
        {
            xNearest = xCenter;
        }
        else if(abs(xCenter - x1) <= abs(xCenter - x2))
        {
            xNearest = x1;
        }
        else
        {
            xNearest = x2;
        }
        if(yCenter >= y1 && yCenter <= y2)
        {
            yNearest = yCenter;
        }
        else if(abs(yCenter - y1) <= abs(yCenter - y2))
        {
            yNearest = y1;
        }
        else
        {
            yNearest = y2;
        }
        dist = sqrt(pow(xCenter - xNearest, 2) + pow(yCenter - yNearest, 2));
        return !(dist > radius);
    }
};