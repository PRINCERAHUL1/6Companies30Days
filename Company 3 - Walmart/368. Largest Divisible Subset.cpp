class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        if(n == 0)
            return res;
        
        if(n == 1)
            return nums;
                
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int maxId = 0;
        vector<int> dp(n, 1);

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j] == 0 && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+ dp[j];
                }
            }

            if(maxi < dp[i])
            {
                maxi = dp[i];
                maxId = i;
            }
        }

        if (maxi == 1)
        {
            res.push_back(nums[0]);
            return res;
        }

        int cur = nums[maxId];
        int curMax = maxi;

        for(int i=maxId; i>=0; i--)
        {
            if(cur%nums[i] == 0 && dp[i] == curMax)
            {
                res.push_back(nums[i]);
                cur = nums[i];
                curMax--;
            }
        }

        return res;
    }
};
