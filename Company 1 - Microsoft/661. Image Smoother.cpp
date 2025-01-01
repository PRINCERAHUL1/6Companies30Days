class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector< vector<int>> res(n, vector<int>(m));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int count=0, total=0;

                for(int r=i-1; r<i+2; r++)
                {
                    for(int c=j-1; c<j+2; c++)
                    {
                        if(r == n || c == m || r<0 || c<0)
                            continue;
                        
                        total += img[r][c];
                        count++;
                    }
                }

                res[i][j] = total/count;
            }
        }

        return res;
    }
};
