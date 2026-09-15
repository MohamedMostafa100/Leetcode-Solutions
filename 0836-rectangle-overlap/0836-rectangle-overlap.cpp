class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool xCheck1 = (rec2[0] >= rec1[0] && rec2[0] < rec1[2]) || (rec1[0] >= rec2[0] && rec1[0] < rec2[2]);
        bool xCheck2 = (rec2[2] > rec1[0] && rec2[2] <= rec1[2]) || (rec1[2] > rec2[0] && rec1[2] <= rec2[2]);
        bool yCheck1 = (rec2[1] >= rec1[1] && rec2[1] < rec1[3]) || (rec1[1] >= rec2[1] && rec1[1] < rec2[3]);
        bool yCheck2 = (rec2[3] > rec1[1] && rec2[3] <= rec1[3]) || (rec1[3] > rec2[1] && rec1[3] <= rec2[3]);
        return (xCheck1 && yCheck1) || (xCheck1 && yCheck2) ||  (xCheck2 && yCheck1) || (xCheck2 && yCheck2);
    }
};