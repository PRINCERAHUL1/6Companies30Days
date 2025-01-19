class Solution {
public:

    int helper(int subtree, vector<vector<int>> &dist, int n)
    {
        int cntN = 0;
        int cntE = 0;
        int mxd = 0;

        for(int i=0; i<n; i++)
        {
            if(((subtree>>i)&1) == 0)
                continue;

            cntN++;
            for(int j=i+1; j<n; j++)
            {
                if(((subtree>>j)&1) == 0)
                    continue;
                
                if(dist[i][j] == 1)
                    cntE++;
                
                mxd = max(mxd, dist[i][j]);
            }
        }

        if(cntN == cntE+1)
            return mxd;
        
        return -1;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> v(n-1, 0);
        vector<vector<int>> dist(15, vector<int>(15, INT_MAX));

        for(auto edge: edges)
        {
            dist[edge[0]-1][edge[1]-1] = 1;
            dist[edge[1]-1][edge[0]-1] = 1;
        }

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dist[i][k] == INT_MAX || dist[j][k] == INT_MAX)
                        continue;
                    
                    dist[i][j] = dist[j][i] = min({dist[i][j], dist[j][i], dist[i][k]+dist[k][j]});
                }
            }
        }

        for(int i=0; i<(1<<n); i++)
        {
            int res = helper(i, dist, n);
            if(res>0)
                v[res-1]++;
        }

        return v;
    }
};
