class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int minX = min(x2, xCenter);
        int minY = min(y2, yCenter);

        int nearestX = max(x1, minX);
        int nearestY = max(y1, minY);
        
        int distX = abs(nearestX - xCenter);
        int distY = abs(nearestY - yCenter);

        int dist = sqrt(distX*distX + distY*distY);

        if(dist <= radius)
            return true;
        else
            return false;
    }
};
