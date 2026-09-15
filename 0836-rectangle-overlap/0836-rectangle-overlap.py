class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        xCheck1 = (rec2[0] >= rec1[0] and rec2[0] < rec1[2]) or (rec1[0] >= rec2[0] and rec1[0] < rec2[2])
        xCheck2 = (rec2[2] > rec1[0] and rec2[2] <= rec1[2]) or (rec1[2] > rec2[0] and rec1[2] <= rec2[2])
        yCheck1 = (rec2[1] >= rec1[1] and rec2[1] < rec1[3]) or (rec1[1] >= rec2[1] and rec1[1] < rec2[3])
        yCheck2 = (rec2[3] > rec1[1] and rec2[3] <= rec1[3]) or (rec1[3] > rec2[1] and rec1[3] <= rec2[3])
        return (xCheck1 and yCheck1) or (xCheck1 and yCheck2) or  (xCheck2 and yCheck1) or (xCheck2 and yCheck2)