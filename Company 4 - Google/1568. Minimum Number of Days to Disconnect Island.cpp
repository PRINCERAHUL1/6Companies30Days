class Solution {
public:

    int m, n;

    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = true;

        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
    }

    int numberOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int islands = numberOfIsland(grid);

        if(islands>1 || islands == 0)
            return 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    islands = numberOfIsland(grid);
                    grid[i][j] = 1;

                    if(islands>1 || islands == 0)
                        return 1;
                }
            }
        }

        return 2;
    }
};
