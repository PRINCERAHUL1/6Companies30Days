class Solution {
public:

    int helper(vector<int> &prices, int pos, int k, bool toBuy, int n, vector<vector<vector<int>>> &dp)
    {
        if(pos == n || k == 0)
            return 0;
        
        if(dp[pos][k][toBuy] != -1)
            return dp[pos][k][toBuy];

        int op1 = 0;
        int op2 = 0;

        if(toBuy)
        {
            op1 = -prices[pos] + helper(prices, pos+1, k, !toBuy, n, dp);
            op2 = helper(prices, pos+1, k, toBuy, n, dp);
        }
        else
        {
            op1 = prices[pos] + helper(prices, pos+1, k-1, !toBuy, n, dp);
            op2 = helper(prices, pos+1, k, toBuy, n, dp);
        }

        return dp[pos][k][toBuy] = max(op1, op2);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (2, -1)));

        return helper(prices, 0, k, true, n, dp);
    }
};
