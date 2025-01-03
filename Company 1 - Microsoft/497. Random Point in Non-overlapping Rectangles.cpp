class Solution {
public:

    int numPts;
    vector<int> rectCount;
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>>& rects) {
        numPts = 0;
        this->rects = rects;

        for(vector<int> &rect: rects)
        {
            numPts += (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1);
            rectCount.push_back(numPts);
        }

    }
    
    vector<int> pick() {
        int ptIdx = rand()%numPts;
        int l = 0;
        int r = rects.size()-1;

        while(l<r)
        {
            int mid = l+ (r-l)/2;

            if(rectCount[mid] <= ptIdx)
                l = mid+1;
            else
                r = mid;
        }

        vector<int> &rect = rects[l];
        int xPts = rect[2] - rect[0] + 1;
        int yPts = rect[3] - rect[1] + 1;
        int ptsinRect = xPts*yPts;
        int ptStart = rectCount[l] - ptsinRect;
        int offset = ptIdx - ptStart;

        return {rect[0] + offset%xPts, rect[1] + offset/xPts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
