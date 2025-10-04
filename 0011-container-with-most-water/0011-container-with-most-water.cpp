class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r)
        {
            area = max(area, (r - l) * min(height[l], height[r]));
            if(height[l] > height[r])
            {
                r--;
            }
            else if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        return area;
    }
};