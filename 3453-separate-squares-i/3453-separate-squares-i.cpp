class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totArea = 0;
        double minY = INT_MAX;
        double maxY = 0;
        double eps = pow(10, -5);
        for(int i = 0; i < squares.size(); i++)
        {
            totArea += (double)squares[i][2] * squares[i][2];
            minY = min(minY, (double)squares[i][1]);
            maxY = max(maxY, (double)squares[i][1] + squares[i][2]);
        }
        while(abs(maxY - minY) > eps)
        {
            double mid = (minY + maxY) / 2;
            double area = calcArea(squares, mid);
            if(area * 2 >= totArea)
            {
                maxY = mid;
            }
            else
            {
                minY = mid;
            }
        }
        return maxY;
    }
private:
    double calcArea(vector<vector<int>>& squares, double y)
    {
        double area = 0;
        for(int i = 0; i < squares.size(); i++)
        {
            area += (double)squares[i][2] * max(0.0, min((double)squares[i][2], y - squares[i][1]));
        }
        return area;
    }
};