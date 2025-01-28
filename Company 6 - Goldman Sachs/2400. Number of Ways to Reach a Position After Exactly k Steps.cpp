class Solution {
public:

    long long dp[4001][1001];

    long long count(int cur, int target, int k)
    {
        if(k==0 && cur==target)
            return 1;
        if(k == 0)
            return 0;
        
        if(dp[cur+1000][k] != -1)
            return dp[cur+1000][k];
        
        long long a = count(cur+1, target, k-1);
        a += count(cur-1, target, k-1);

        return dp[cur+1000][k] = a%1000000007;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0; i<=3001; i++)
        {
            for(int j=0; j<=k; j++)
                dp[i][j] = -1;
        }

        long long res = count(startPos, endPos, k);
        return res%1000000007;
    }
};
