class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, n);
        dp[0] = 0;

        for(int i=0; i<n; i++)
        {
            for(auto dict: dictionary)
            {
                if(s.substr(i, dict.size()) == dict)
                    dp[i + dict.size()] = min(dp[i + dict.size()], dp[i]);
            }

            dp[i+1] = min(dp[i+1], dp[i]+1);
        }

        return dp.back();
    }
};
