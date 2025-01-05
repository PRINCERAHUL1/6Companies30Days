class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int dist[26][26];
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INT_MAX;
            }
        }

        for(int i=0; i<original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = (cost[i] < dist[u][v]) ? cost[i] : dist[u][v];
        }

        for(int k=0; k<26; k++)
        {
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        long int totalCost = 0;
        for(int i=0; i<source.size(); i++)
        {
            if(source[i] != target[i])
            {
                int u = source[i] - 'a';
                int v = target[i] - 'a';

                if(dist[u][v] == INT_MAX)
                    return -1;

                totalCost += dist[u][v];
            }
        }

        return totalCost;
    }
};
