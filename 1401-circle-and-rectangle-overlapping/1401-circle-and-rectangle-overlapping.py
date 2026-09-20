class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        xNearest = 0
        yNearest = 0
        dist = 0
        if xCenter >= x1 and xCenter <= x2:
            xNearest = xCenter
        elif abs(xCenter - x1) <= abs(xCenter - x2):
            xNearest = x1
        else:
            xNearest = x2
        if yCenter >= y1 and yCenter <= y2:
            yNearest = yCenter
        elif abs(yCenter - y1) <= abs(yCenter - y2):
            yNearest = y1
        else:
            yNearest = y2
        dist = sqrt((xCenter - xNearest)**2 + (yCenter - yNearest)**2)
        return not(dist > radius)