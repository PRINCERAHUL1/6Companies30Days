class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = 1;
        int maxV = 1;
        int c = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        for(int i=1; i<hBars.size(); i++)
        {
            if(hBars[i] == hBars[i-1]+1)
                c++;
            else
                c=1;
            
            maxH = max(maxH, c);
        }
        c=1;
        
        for(int i=1; i<vBars.size(); i++)
        {
            if(vBars[i] == vBars[i-1]+1)
                c++;
            else
                c=1;
            
            maxV = max(maxV, c);
        }

        int x = min(maxH+1, maxV+1);

        return x*x;
    }
};
