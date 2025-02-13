class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int time = 0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                    rotten.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        while(!rotten.empty())
        {
            int n = rotten.size();

            for(int i=0; i<n; i++)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                if(x>0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    fresh--;
                    rotten.push({x-1, y});
                }

                if(y>0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    fresh--;
                    rotten.push({x, y-1});
                }

                if(x<row-1 && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    fresh--;
                    rotten.push({x+1, y});
                }

                if(y<col-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    fresh--;
                    rotten.push({x, y+1});
                }
            }

            if(!rotten.empty())
                time++;
        }

        return (fresh == 0) ? time : -1;
    }
};
